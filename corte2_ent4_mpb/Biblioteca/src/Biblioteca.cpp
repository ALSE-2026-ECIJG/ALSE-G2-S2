#include "Biblioteca.h"

#include <algorithm>
#include <cctype>
#include <iostream>

std::string Biblioteca::aMinusculas(const std::string& texto) {
    std::string resultado = texto;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(),
                    [](unsigned char c) { return std::tolower(c); });
    return resultado;
}

void Biblioteca::agregarLibro(const Libro& libro) {
    libros_.push_back(libro);
}

bool Biblioteca::eliminarLibro(const std::string& isbn) {
    // std::find_if recorre el vector hasta encontrar el primer elemento
    // que cumpla la condición (el lambda). Devuelve un iterador: si no
    // encuentra nada, ese iterador es igual a libros_.end().
    auto it = std::find_if(libros_.begin(), libros_.end(),
                            [&isbn](const Libro& l) { return l.getIsbn() == isbn; });

    if (it == libros_.end()) {
        return false; // no se encontró ningún libro con ese ISBN
    }

    libros_.erase(it); // elimina el elemento apuntado por el iterador
    return true;
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::vector<Libro> resultado;
    std::string buscado = aMinusculas(titulo);

    for (const Libro& libro : libros_) {
        std::string tituloLibro = aMinusculas(libro.getTitulo());
        // find() devuelve std::string::npos si NO encuentra la subcadena
        if (tituloLibro.find(buscado) != std::string::npos) {
            resultado.push_back(libro);
        }
    }
    return resultado;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultado;
    std::string buscado = aMinusculas(autor);

    for (const Libro& libro : libros_) {
        std::string autorLibro = aMinusculas(libro.getAutor());
        if (autorLibro.find(buscado) != std::string::npos) {
            resultado.push_back(libro);
        }
    }
    return resultado;
}

void Biblioteca::mostrarDisponibles() const {
    std::cout << "--- Libros disponibles ---\n";
    bool hayDisponibles = false;

    for (const Libro& libro : libros_) {
        if (libro.isDisponible()) {
            std::cout << "  \"" << libro.getTitulo() << "\" de " << libro.getAutor()
                       << " (ISBN: " << libro.getIsbn() << ")\n";
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles) {
        std::cout << "  (No hay libros disponibles en este momento)\n";
    }
}

void Biblioteca::mostrarTodos() const {
    std::cout << "--- Todos los libros ---\n";

    if (libros_.empty()) {
        std::cout << "  (La biblioteca no tiene libros registrados)\n";
        return;
    }

    for (const Libro& libro : libros_) {
        std::cout << "  \"" << libro.getTitulo() << "\" de " << libro.getAutor()
                   << " (ISBN: " << libro.getIsbn() << ") - "
                   << (libro.isDisponible() ? "Disponible" : "Prestado") << "\n";
    }
}

std::size_t Biblioteca::cantidadLibros() const {
    return libros_.size();
}
