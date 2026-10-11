#include <iostream>
#include <iomanip>
#include "CarritoCompras.h"
#include "Usuario.h"
using namespace std;

int main() {
    Producto p1("Cuaderno", 6500, 10);
    Producto p2("Lapiz", 1200, 20);
    Producto p3("Regla", 2500, 8);
    Producto* productos[] = {&p1, &p2, &p3};
    CarritoCompras carrito;
    Usuario usuario("Cliente");
    int opcion, cantidad, numero;
    string nombre;

    do {
        cout << "\n--- CARRITO DE COMPRAS ---\n";
        cout << "1. Ver productos\n2. Agregar producto\n3. Eliminar producto\n";
        cout << "4. Ver carrito y total\n5. Finalizar compra\n6. Ver historial\n0. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            for (Producto* p : productos)
                cout << p->getNombre() << " | $" << p->getPrecio()
                     << " | Stock: " << p->getStock() << endl;
        } else if (opcion == 2) {
            cout << "Producto (Cuaderno, Lapiz, Regla): "; getline(cin, nombre);
            cout << "Cantidad: "; cin >> cantidad; cin.ignore();
            bool agregado = false;
            for (Producto* p : productos) {
                if (p->getNombre() == nombre) {
                    agregado = carrito.agregarProducto(p, cantidad);
                    break;
                }
            }
            if (agregado) cout << "Producto agregado al carrito.\n";
            else cout << "No se pudo agregar el producto.\n";
        } else if (opcion == 3) {
            cout << "Nombre del producto: "; getline(cin, nombre);
            if (carrito.eliminarProducto(nombre)) cout << "Producto eliminado.\n";
            else cout << "No se encontro el producto en el carrito.\n";
        } else if (opcion == 4) {
            carrito.mostrarCarrito();
        } else if (opcion == 5) {
            double total = carrito.calcularTotal();
            if (total > 0) {
                usuario.agregarCompra(total);
                cout << "Compra registrada. Total: $" << total << endl;
                carrito = CarritoCompras();
            } else cout << "El carrito esta vacio.\n";
        } else if (opcion == 6) {
            usuario.mostrarHistorial();
        }
    } while (opcion != 0);
    return 0;
}
