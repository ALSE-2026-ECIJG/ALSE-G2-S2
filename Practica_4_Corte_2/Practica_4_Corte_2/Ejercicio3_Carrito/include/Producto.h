#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;
class Producto {
private:
    string nombre;
    double precio;
    int stock;
public:
    Producto(string nombre, double precio, int stock);
    string getNombre();
    double getPrecio();
    int getStock();
    void cambiarStock(int cantidad);
};
#endif
