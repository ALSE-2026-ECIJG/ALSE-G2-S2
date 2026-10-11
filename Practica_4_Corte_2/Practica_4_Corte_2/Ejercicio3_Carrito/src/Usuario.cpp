#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario(string nombre) { this->nombre = nombre; }
void Usuario::agregarCompra(double total) { historialCompras.push_back(total); }
void Usuario::mostrarHistorial() {
    cout << "Historial de compras de " << nombre << ":\n";
    if (historialCompras.empty()) cout << "Todavia no hay compras.\n";
    for (double total : historialCompras) cout << "$" << total << endl;
}
