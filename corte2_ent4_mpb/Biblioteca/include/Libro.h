#ifndef LIBRO_H
#define LIBRO_H

#include <string>

/**
 * @class Libro
 * @brief Representa un libro individual dentro de la biblioteca.
 *
 * Es una clase sencilla (a veces llamada "clase de datos" o POJO/POCO):
 * guarda la información de un libro y ofrece operaciones básicas sobre
 * ese único libro (consultar y cambiar su disponibilidad). No sabe nada
 * sobre otros libros ni sobre la colección que los contiene; esa
 * responsabilidad es de la clase Biblioteca.
 */
class Libro {
public:
    /**
     * @brief Construye un libro con sus datos básicos.
     * @param titulo Título del libro.
     * @param autor  Autor del libro.
     * @param isbn   Código ISBN (o número de serie) que lo identifica.
     *
     * El libro se crea disponible (disponible = true) por defecto, ya
     * que al agregarse a la biblioteca todavía no ha sido prestado.
     */
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn);

    // --- Getters: permiten leer los atributos desde fuera de la clase ---

    /** @brief Devuelve el título del libro. */
    std::string getTitulo() const;

    /** @brief Devuelve el autor del libro. */
    std::string getAutor() const;

    /** @brief Devuelve el ISBN del libro. */
    std::string getIsbn() const;

    /** @brief Indica si el libro está disponible actualmente. */
    bool isDisponible() const;

    // --- Operaciones propias del libro ---

    /**
     * @brief Marca el libro como prestado (lo pone no disponible).
     */
    void prestar();

    /**
     * @brief Marca el libro como devuelto (lo pone disponible de nuevo).
     */
    void devolver();

private:
    std::string titulo_;
    std::string autor_;
    std::string isbn_;
    bool disponible_;
};

#endif // LIBRO_H
