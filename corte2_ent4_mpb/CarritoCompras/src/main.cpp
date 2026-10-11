/**
 * @file main.cpp
 * @brief Programa de demostración del sistema de carrito de compras.
 */

#include <iostream>

#include "CarritoCompras.h"
#include "Producto.h"
#include "Usuario.h"

int main() {
    // 1) Catálogo de productos (dueños reales de los objetos Producto;
    //    el carrito solo los referencia por puntero, nunca los copia
    //    ni los destruye).
    Producto cafe("Café", 12.50, 10);
    Producto te("Té verde", 8.00, 5);
    Producto galletas("Galletas", 4.25, 20);

    Usuario usuario("Mariana");
    CarritoCompras carrito;

    // 2) Agregar productos al carrito.
    std::cout << "Agregando productos al carrito...\n";
    carrito.agregarProducto(&cafe, 2);
    carrito.agregarProducto(&te, 1);
    carrito.agregarProducto(&galletas, 3);

    std::cout << "\n";
    carrito.mostrarCarrito();

    // 3) Intentar agregar más unidades de las que hay en stock.
    std::cout << "\nIntentando agregar 10 unidades más de té (solo quedan "
               << te.getStock() << ")...\n";
    carrito.agregarProducto(&te, 10);

    // 4) Agregar más café (ya está en el carrito: debe sumarse, no duplicarse).
    std::cout << "\nAgregando 1 café más...\n";
    carrito.agregarProducto(&cafe, 1);
    std::cout << "\n";
    carrito.mostrarCarrito();

    // 5) Eliminar un producto del carrito.
    std::cout << "\nEliminando las galletas del carrito...\n";
    carrito.eliminarProducto("Galletas");
    std::cout << "Stock de galletas tras eliminarlas del carrito: " << galletas.getStock()
               << "\n\n";
    carrito.mostrarCarrito();

    // 6) Confirmar la compra: se registra en el historial del usuario.
    std::cout << "\nConfirmando la compra...\n";
    usuario.agregarCompraAlHistorial(carrito);

    std::cout << "\n";
    carrito.mostrarCarrito(); // debería mostrar el carrito ya vacío

    // 7) Hacer una segunda compra para ver que el historial acumula.
    std::cout << "\nHaciendo una segunda compra (1 té)...\n";
    carrito.agregarProducto(&te, 1);
    usuario.agregarCompraAlHistorial(carrito);

    std::cout << "\n";
    usuario.mostrarHistorial();

    return 0;
}
