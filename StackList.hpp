#ifndef STACKLIST_HPP
#define STACKLIST_HPP

#include "Cliente.hpp" // Incluir la estructura cliente

// Nodo que representa un elemento de la pila
struct StackNode {
    StackNode* next;  // Apunta al siguiente nodo en la pila
    cliente data;     // Contiene los datos del cliente

    // Constructor del nodo
    StackNode(cliente c) : data(c), next(nullptr) {}
};

// Clase que implementa una pila personalizada
class StackList {
private:
    StackNode* topNode; // Nodo superior de la pila
    int size;           // Número de elementos en la pila

public:
    // Constructor
    StackList() : topNode(nullptr), size(0) {}

    // Destructor
    ~StackList();

    // Métodos principales
    void push(cliente c);       // Agregar un cliente a la pila
    void pop();                 // Eliminar el cliente en la cima
    cliente top() const;        // Obtener el cliente en la cima
    bool empty() const;         // Verificar si la pila está vacía
    int get_size() const;       // Obtener el tamaño de la pila
};

#endif // STACKLIST_HPP

