#include "Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(string titulo, string autor, string isbn) {
    this->titulo = titulo;
    this->autor = autor;
    this->isbn = isbn;
    disponible = true;
}

string Libro::getTitulo() { return titulo; }
string Libro::getAutor() { return autor; }
string Libro::getIsbn() { return isbn; }
bool Libro::estaDisponible() { return disponible; }
void Libro::cambiarDisponibilidad(bool estado) { disponible = estado; }

void Libro::mostrar() {
    cout << "Titulo: " << titulo << " | Autor: " << autor
         << " | ISBN: " << isbn
         << " | Disponible: " << (disponible ? "Si" : "No") << endl;
}
