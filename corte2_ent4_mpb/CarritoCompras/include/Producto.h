#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Representa un producto del catálogo de la tienda.
 *
 * Guarda los datos básicos de un producto: nombre, precio y stock
 * (unidades disponibles en inventario). No sabe nada sobre carritos ni
 * usuarios; esa es responsabilidad de ItemCarrito y CarritoCompras.
 */
class Producto {
public:
    /**
     * @brief Construye un producto.
     * @param nombre Nombre del producto.
     * @param precio Precio unitario del producto.
     * @param stock  Unidades disponibles en inventario.
     */
    Producto(const std::string& nombre, double precio, int stock);

    // --- Getters ---

    /** @brief Devuelve el nombre del producto. */
    std::string getNombre() const;

    /** @brief Devuelve el precio unitario del producto. */
    double getPrecio() const;

    /** @brief Devuelve las unidades actualmente disponibles en stock. */
    int getStock() const;

    // --- Operaciones sobre el stock ---

    /**
     * @brief Intenta reservar unidades del stock (p. ej. al agregarlas
     *        a un carrito).
     * @param cantidad Unidades a reservar.
     * @return true si había suficiente stock y se descontó; false si
     *         no había suficientes unidades disponibles (en ese caso,
     *         el stock no se modifica).
     */
    bool reducirStock(int cantidad);

    /**
     * @brief Devuelve unidades al stock (p. ej. al quitarlas de un
     *        carrito o cancelar una compra).
     * @param cantidad Unidades a devolver.
     */
    void aumentarStock(int cantidad);

private:
    std::string nombre_;
    double precio_;
    int stock_;
};

#endif // PRODUCTO_H
