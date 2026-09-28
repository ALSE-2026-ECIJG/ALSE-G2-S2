#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {

void Bankaccount::open() {
    std::lock_guard<std::mutex> candado(cerrojo_);
    if (abierta_) throw std::runtime_error("La cuenta ya esta abierta");
    abierta_ = true;
    saldo_ = 0;
}

void Bankaccount::close() {
    std::lock_guard<std::mutex> candado(cerrojo_);
    if (!abierta_) throw std::runtime_error("La cuenta ya esta cerrada");
    abierta_ = false;
}

int Bankaccount::balance() {
    std::lock_guard<std::mutex> candado(cerrojo_);
    if (!abierta_) throw std::runtime_error("La cuenta esta cerrada");
    return saldo_;
}

void Bankaccount::deposit(int monto) {
    std::lock_guard<std::mutex> candado(cerrojo_);
    if (!abierta_) throw std::runtime_error("La cuenta esta cerrada");
    if (monto <= 0) throw std::runtime_error("El deposito debe ser positivo");
    saldo_ += monto;
}

void Bankaccount::withdraw(int monto) {
    std::lock_guard<std::mutex> candado(cerrojo_);
    if (!abierta_) throw std::runtime_error("La cuenta esta cerrada");
    if (monto <= 0) throw std::runtime_error("El retiro debe ser positivo");
    if (monto > saldo_) throw std::runtime_error("Saldo insuficiente");
    saldo_ -= monto;
}

}  // namespace Bankaccount
