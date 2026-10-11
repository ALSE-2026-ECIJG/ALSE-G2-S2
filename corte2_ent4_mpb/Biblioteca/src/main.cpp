/**
 * @file main.cpp
 * @brief Programa de demostración del sistema de gestión de biblioteca.
 */

#include <iostream>

#include "Biblioteca.h"
#include "Libro.h"

int main() {
    Biblioteca biblioteca;

    // 1) Agregar libros
    biblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", "001"));
    biblioteca.agregarLibro(Libro("El amor en los tiempos del cólera", "Gabriel García Márquez", "002"));
    biblioteca.agregarLibro(Libro("Rayuela", "Julio Cortázar", "003"));
    biblioteca.agregarLibro(Libro("Ficciones", "Jorge Luis Borges", "004"));

    std::cout << "Libros registrados: " << biblioteca.cantidadLibros() << "\n\n";
    biblioteca.mostrarTodos();

    // 2) Buscar por autor
    std::cout << "\nBusqueda por autor \"García Márquez\":\n";
    for (const Libro& libro : biblioteca.buscarPorAutor("García Márquez")) {
        std::cout << "  -> " << libro.getTitulo() << "\n";
    }

    // 3) Buscar por título (parcial, sin importar mayúsculas)
    std::cout << "\nBusqueda por título \"rayuela\":\n";
    for (const Libro& libro : biblioteca.buscarPorTitulo("rayuela")) {
        std::cout << "  -> " << libro.getTitulo() << " de " << libro.getAutor() << "\n";
    }

    // 4) Simular un préstamo: buscamos el libro y lo marcamos prestado.
    //    (Nota: buscarPorTitulo devuelve COPIAS, así que para modificar
    //    el libro real dentro de la biblioteca necesitaríamos un método
    //    adicional, p. ej. prestarLibro(isbn). Lo dejamos como ejercicio
    //    de extensión -- ver la sección de mejoras más abajo.)

    // 5) Eliminar un libro
    std::cout << "\nEliminando el libro con ISBN 004...\n";
    bool eliminado = biblioteca.eliminarLibro("004");
    std::cout << "¿Se eliminó? " << (eliminado ? "Sí" : "No") << "\n\n";

    biblioteca.mostrarTodos();

    // 6) Intentar eliminar un ISBN que no existe
    std::cout << "\nIntentando eliminar un ISBN inexistente (999)...\n";
    bool eliminado2 = biblioteca.eliminarLibro("999");
    std::cout << "¿Se eliminó? " << (eliminado2 ? "Sí" : "No") << "\n\n";

    // 7) Mostrar disponibles
    biblioteca.mostrarDisponibles();

    return 0;
}
