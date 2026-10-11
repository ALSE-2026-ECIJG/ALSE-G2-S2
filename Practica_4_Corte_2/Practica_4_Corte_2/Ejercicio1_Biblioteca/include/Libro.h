#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponible;

public:
    Libro(string titulo, string autor, string isbn);
    string getTitulo();
    string getAutor();
    string getIsbn();
    bool estaDisponible();
    void cambiarDisponibilidad(bool estado);
    void mostrar();
};

#endif
