/*#ifndef WALLET_H
#define WALLET_H

#include <mutex>

class Wallet {
private:
    unsigned int rupees;
    mutable std::mutex mtx; 
public:
    explicit Wallet(unsigned int initial = 0);
    void credit(unsigned int val);
    void debit(unsigned int val);
    unsigned int balance() const;
};

#endif
*/

// 4. Instant Wallet

#ifndef WALLET_H
#define WALLET_H

#include <mutex>

class Wallet {
private:
    unsigned int rupees;
    unsigned int virtual_rupees;

    mutable std::mutex mtx_rupees;
    mutable std::mutex mtx_virtual;

public:
    explicit Wallet(unsigned int initial = 0);

    void credit(unsigned int val);
    void debit(unsigned int val);

    bool virtual_credit(unsigned int val);
    bool virtual_debit(unsigned int val);

    unsigned int balance() const;
};

#endif
