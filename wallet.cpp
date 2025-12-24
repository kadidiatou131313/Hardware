/* 
// 1 et 2
#include "wallet.h"

Wallet::Wallet(unsigned int initial) : rupees(initial) {}

void Wallet::credit(unsigned int val) {
    rupees += val;
}

void Wallet::debit(unsigned int val) {
    if (rupees >= val) {
        rupees -= val;
    }
}

unsigned int Wallet::balance() const {
    return rupees;
}
*/


// 3

/*#include "wallet.h"
#include <mutex>

Wallet::Wallet(unsigned int initial) : rupees(initial) {}

void Wallet::credit(unsigned int val) {
    std::lock_guard<std::mutex> lock(mtx);
    rupees += val;
}

void Wallet::debit(unsigned int val) {
    std::lock_guard<std::mutex> lock(mtx);
    if (rupees >= val) {
        rupees -= val;
    }
}

unsigned int Wallet::balance() const {
    std::lock_guard<std::mutex> lock(mtx);
    return rupees;
}
    */

// 4. Instant Wallet

#include "wallet.h"
#include <thread>

Wallet::Wallet(unsigned int initial)
    : rupees(initial), virtual_rupees(initial) {}

void Wallet::credit(unsigned int val) {
    std::lock_guard<std::mutex> lock(mtx_rupees);
    rupees += val;
}

void Wallet::debit(unsigned int val) {
    std::lock_guard<std::mutex> lock(mtx_rupees);
    if (rupees >= val) {
        rupees -= val;
    }
}

bool Wallet::virtual_credit(unsigned int val) {
    {
        std::lock_guard<std::mutex> lock(mtx_virtual);
        virtual_rupees += val;
    }

    std::thread(&Wallet::credit, this, val).detach();
    return true;
}

bool Wallet::virtual_debit(unsigned int val) {
    {
        std::lock_guard<std::mutex> lock(mtx_virtual);
        if (virtual_rupees < val)
            return false;
        virtual_rupees -= val;
    }

    std::thread(&Wallet::debit, this, val).detach();
    return true;
}

unsigned int Wallet::balance() const {
    std::lock_guard<std::mutex> lock(mtx_virtual);
    return virtual_rupees;
}
