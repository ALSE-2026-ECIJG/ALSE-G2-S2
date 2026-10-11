#include <iostream>
#include "Biblioteca.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    int opcion;
    string titulo, autor, isbn;

    do {
        cout << "\n--- BIBLIOTECA ---\n";
        cout << "1. Agregar libro\n2. Eliminar libro\n3. Buscar por titulo\n";
        cout << "4. Buscar por autor\n5. Mostrar disponibles\n6. Mostrar todos\n0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Titulo: "; getline(cin, titulo);
            cout << "Autor: "; getline(cin, autor);
            cout << "ISBN: "; getline(cin, isbn);
            biblioteca.agregarLibro(Libro(titulo, autor, isbn));
        } else if (opcion == 2) {
            cout << "ISBN del libro a eliminar: "; getline(cin, isbn);
            biblioteca.eliminarLibro(isbn);
        } else if (opcion == 3) {
            cout << "Titulo: "; getline(cin, titulo);
            biblioteca.buscarTitulo(titulo);
        } else if (opcion == 4) {
            cout << "Autor: "; getline(cin, autor);
            biblioteca.buscarAutor(autor);
        } else if (opcion == 5) {
            biblioteca.mostrarDisponibles();
        } else if (opcion == 6) {
            biblioteca.mostrarTodos();
        }
    } while (opcion != 0);

    return 0;
}
