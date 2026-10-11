#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>

#include "Libro.h"

/**
 * @class Biblioteca
 * @brief Administra una colección de objetos Libro.
 *
 * A diferencia de Libro (que representa un único libro), esta clase
 * opera sobre el conjunto completo: agregar, eliminar, buscar y listar.
 * Internamente guarda los libros en un std::vector<Libro>.
 */
class Biblioteca {
public:
    /**
     * @brief Agrega un libro nuevo a la colección.
     * @param libro El libro a agregar (se copia internamente).
     */
    void agregarLibro(const Libro& libro);

    /**
     * @brief Elimina un libro de la colección, identificado por su ISBN.
     * @param isbn ISBN del libro a eliminar.
     * @return true si se encontró y eliminó el libro; false si no existía
     *         ningún libro con ese ISBN.
     */
    bool eliminarLibro(const std::string& isbn);

    /**
     * @brief Busca todos los libros cuyo título contenga el texto dado.
     * @param titulo Texto a buscar dentro del título (no distingue
     *               mayúsculas/minúsculas).
     * @return Vector con los libros encontrados (vacío si no hay
     *         coincidencias).
     */
    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;

    /**
     * @brief Busca todos los libros cuyo autor contenga el texto dado.
     * @param autor Texto a buscar dentro del autor (no distingue
     *              mayúsculas/minúsculas).
     * @return Vector con los libros encontrados (vacío si no hay
     *         coincidencias).
     */
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;

    /**
     * @brief Imprime en consola los libros actualmente disponibles.
     */
    void mostrarDisponibles() const;

    /**
     * @brief Imprime en consola todos los libros de la biblioteca,
     *        indicando su disponibilidad.
     */
    void mostrarTodos() const;

    /**
     * @brief Cantidad total de libros registrados (disponibles o no).
     */
    std::size_t cantidadLibros() const;

private:
    std::vector<Libro> libros_;

    /**
     * @brief Convierte una cadena a minúsculas, usada internamente para
     *        hacer búsquedas sin distinguir mayúsculas/minúsculas.
     */
    static std::string aMinusculas(const std::string& texto);
};

#endif // BIBLIOTECA_H
