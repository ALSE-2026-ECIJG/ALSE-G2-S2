#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
using namespace std;
class Usuario {
private:
    string nombre;
    vector<double> historialCompras;
public:
    Usuario(string nombre);
    void agregarCompra(double total);
    void mostrarHistorial();
};
#endif
