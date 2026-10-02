#include <iostream>
#include <mutex>

using namespace std;

class BankAccount {
private:
    int saldo;
    bool abierta;
    mutex bloqueo;

public:

    BankAccount() {
        saldo = 0;
        abierta = false;
    }

    void open() {

        lock_guard<mutex> candado(bloqueo);

        abierta = true;
        saldo = 0;
    }

    void close() {

        lock_guard<mutex> candado(bloqueo);

        abierta = false;
    }

    int balance() {

        lock_guard<mutex> candado(bloqueo);

        if (!abierta) {
            return -1;
        }

        return saldo;
    }

    void deposit(int cantidad) {

        lock_guard<mutex> candado(bloqueo);

        if (!abierta) {
            return;
        }

        saldo += cantidad;
    }

    void withdraw(int cantidad) {

        lock_guard<mutex> candado(bloqueo);

        if (!abierta) {
            return;
        }

        if (cantidad <= saldo) {
            saldo -= cantidad;
        }
    }
};

int main() {

    BankAccount cuenta;

    cuenta.open();

    cuenta.deposit(100);

    cout << "Saldo: " << cuenta.balance() << endl;

    cuenta.withdraw(30);

    cout << "Saldo despues del retiro: "
         << cuenta.balance() << endl;

    cuenta.close();

    return 0;
}