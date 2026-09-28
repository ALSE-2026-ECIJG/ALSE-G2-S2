#pragma once
#include <mutex>

namespace Bankaccount {

class Bankaccount {
public:
    void open();
    void close();
    int balance();
    void deposit(int monto);
    void withdraw(int monto);

private:
    std::mutex cerrojo_;
    bool abierta_ = false;
    int saldo_ = 0;
};

}  // namespace Bankaccount
