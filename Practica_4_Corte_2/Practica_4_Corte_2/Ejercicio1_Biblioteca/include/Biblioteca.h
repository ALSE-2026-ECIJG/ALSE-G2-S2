#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(Libro libro);
    bool eliminarLibro(string isbn);
    void buscarTitulo(string titulo);
    void buscarAutor(string autor);
    void mostrarDisponibles();
    void mostrarTodos();
};

#endif
