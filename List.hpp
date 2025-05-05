#ifndef LISTA_HPP
#define LISTA_HPP

#include "Cliente.hpp"  // Asegúrate de que el archivo Cliente.hpp esté correctamente incluido

class ListaDoblementeEnlazadaCliente {
private:
    struct Nodo {
        cliente data;        // Cliente de la lista
        Nodo* siguiente;     // Apuntador al siguiente nodo
        Nodo* anterior;      // Apuntador al nodo anterior

        Nodo(cliente c) : data(c), siguiente(nullptr), anterior(nullptr) {}
    };

    Nodo* cabeza;  // Primer nodo de la lista
    Nodo* cola;    // Último nodo de la lista
    int size;      // Tamaño de la lista

public:
    ListaDoblementeEnlazadaCliente();  // Constructor
    ~ListaDoblementeEnlazadaCliente(); // Destructor

    void insertarAtras(cliente c);       // Insertar un cliente al final
    void imprimirListaIzqDer() const;    // Imprimir lista de izquierda a derecha
};

#endif // LISTA_HPP
