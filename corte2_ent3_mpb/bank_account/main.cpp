#include <iostream>
#include <thread>
#include <vector>
#include "bank_account.h"

int main() {
    Bankaccount::Bankaccount cuenta;
    cuenta.open();

    std::vector<std::thread> hilos;
    for (int i = 0; i < 10; i++) {
        hilos.push_back(std::thread([&cuenta]() { cuenta.deposit(10); }));
    }
    for (auto& h : hilos) h.join();

    std::cout << "Saldo final tras 10 depositos en paralelo: " << cuenta.balance() << " (esperado: 100)\n";
    return 0;
}
