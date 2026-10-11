#include "Libro.h"

Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo_(titulo), autor_(autor), isbn_(isbn), disponible_(true) {
    // Lista de inicialización (arriba, después de los ':'): es la forma
    // preferida en C++ para inicializar atributos, más eficiente que
    // asignarlos dentro del cuerpo del constructor.
}

std::string Libro::getTitulo() const {
    return titulo_;
}

std::string Libro::getAutor() const {
    return autor_;
}

std::string Libro::getIsbn() const {
    return isbn_;
}

bool Libro::isDisponible() const {
    return disponible_;
}

void Libro::prestar() {
    disponible_ = false;
}

void Libro::devolver() {
    disponible_ = true;
}
