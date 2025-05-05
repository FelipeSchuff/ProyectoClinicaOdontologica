#include "List.hpp"
#include <iostream>

// Constructor
ListaDoblementeEnlazadaCliente::ListaDoblementeEnlazadaCliente() : cabeza(nullptr), cola(nullptr), size(0) {}

// Destructor
ListaDoblementeEnlazadaCliente::~ListaDoblementeEnlazadaCliente() {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Insertar un cliente al final
void ListaDoblementeEnlazadaCliente::insertarAtras(cliente c) {
    Nodo* nuevo = new Nodo(c);
    if (!cabeza) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
    size++;
}

// Imprimir lista de izquierda a derecha
void ListaDoblementeEnlazadaCliente::imprimirListaIzqDer() const {
    Nodo* actual = cabeza;
    while (actual) {
        std::cout << "Nombre: " << actual->data.nombre << ", RUT: " << actual->data.rut << ", Prioridad: " << actual->data.nivel_prioridad << std::endl;
        actual = actual->siguiente;
    }
}

