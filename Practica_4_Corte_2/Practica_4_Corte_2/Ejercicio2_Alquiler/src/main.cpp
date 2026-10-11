#include <iostream>
#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"
using namespace std;

int main() {
    SistemaAlquiler sistema;
    int opcion;
    string marca, modelo, placa, tipo;
    int capacidad;

    do {
        cout << "\n--- SISTEMA DE ALQUILER ---\n";
        cout << "1. Registrar auto\n2. Registrar bicicleta\n3. Alquilar\n";
        cout << "4. Devolver\n5. Mostrar disponibles\n0. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Marca: "; getline(cin, marca);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Placa: "; getline(cin, placa);
            cout << "Capacidad de pasajeros: "; cin >> capacidad; cin.ignore();
            sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
        } else if (opcion == 2) {
            cout << "Marca: "; getline(cin, marca);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Codigo: "; getline(cin, placa);
            cout << "Tipo (montana/ruta/urbana): "; getline(cin, tipo);
            sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipo));
        } else if (opcion == 3) {
            cout << "Placa o codigo: "; getline(cin, placa);
            sistema.alquilar(placa);
        } else if (opcion == 4) {
            cout << "Placa o codigo: "; getline(cin, placa);
            sistema.devolver(placa);
        } else if (opcion == 5) {
            sistema.mostrarDisponibles();
        }
    } while (opcion != 0);
    return 0;
}
