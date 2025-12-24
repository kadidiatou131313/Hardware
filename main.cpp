// 1
/*
include <iostream>
#include "wallet.h"
int main() {
    Wallet wallet(100);
    std::cout << "Solde initial : " << wallet.balance() << " rubis\n";
    wallet.credit(50);
    std::cout << "Apres vente : " << wallet.balance() << " rubis\n";
    unsigned int price = 120;
    if (wallet.balance() >= price) {
        wallet.debit(price);
        std::cout << "Achat effectue.\n";
    } else {
        std::cout << "Fonds insuffisants.\n";
    }
    std::cout << "Solde final : " << wallet.balance() << " rubis\n";
    return 0;
}
*/



//2 

/*
#include <iostream>
#include <thread>
#include "wallet.h"

int main() {
    Wallet wallet(100);

    std::cout << "Initial balance: " << wallet.balance() << " rupees\n";

    std::thread t1(&Wallet::credit, &wallet, 50);
    std::thread t2(&Wallet::debit, &wallet, 30);

    t1.join();
    t2.join();

    std::cout << "Final balance: " << wallet.balance() << " rupees\n";

    return 0;
}

*/
// 4. Instant Wallet

#include <iostream>
#include <thread>
#include "wallet.h"

int main() {
    Wallet wallet(100);

    std::cout << "Initial balance: " << wallet.balance() << std::endl;

    std::thread t1([&]() {
        wallet.virtual_debit(60);
    });

    std::thread t2([&]() {
        wallet.virtual_debit(50);
    });

    t1.join();
    t2.join();

    std::cout << "Final balance (virtual): " << wallet.balance() << std::endl;

    return 0;
}
