#include "Biblioteca.h"
#include <iostream>
using namespace std;

void Biblioteca::agregarLibro(Libro libro) {
    libros.push_back(libro);
    cout << "Libro agregado.\n";
}

bool Biblioteca::eliminarLibro(string isbn) {
    for (int i = 0; i < (int)libros.size(); i++) {
        if (libros[i].getIsbn() == isbn) {
            libros.erase(libros.begin() + i);
            cout << "Libro eliminado.\n";
            return true;
        }
    }
    cout << "No se encontro el libro.\n";
    return false;
}

void Biblioteca::buscarTitulo(string titulo) {
    bool encontrado = false;
    for (Libro libro : libros) {
        if (libro.getTitulo() == titulo) {
            libro.mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No hay libros con ese titulo.\n";
}

void Biblioteca::buscarAutor(string autor) {
    bool encontrado = false;
    for (Libro libro : libros) {
        if (libro.getAutor() == autor) {
            libro.mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No hay libros de ese autor.\n";
}

void Biblioteca::mostrarDisponibles() {
    bool hay = false;
    for (Libro libro : libros) {
        if (libro.estaDisponible()) {
            libro.mostrar();
            hay = true;
        }
    }
    if (!hay) cout << "No hay libros disponibles.\n";
}

void Biblioteca::mostrarTodos() {
    if (libros.empty()) cout << "La biblioteca esta vacia.\n";
    for (Libro libro : libros) libro.mostrar();
}
