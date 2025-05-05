#include "StackList.hpp"
#include <stdexcept>

// Destructor para liberar memoria de la pila
StackList::~StackList() {
    while (!empty()) {
        pop();
    }
}

// Método para agregar un cliente a la pila
void StackList::push(cliente c) {
    StackNode* newNode = new StackNode(c);
    newNode->next = topNode;
    topNode = newNode;
    size++;
}

// Método para eliminar el nodo superior de la pila
void StackList::pop() {
    if (empty()) return;
    StackNode* temp = topNode;
    topNode = topNode->next;
    delete temp;
    size--;
}

// Obtener el cliente en el nodo superior de la pila
cliente StackList::top() const {
    if (!empty()) {
        return topNode->data;
    }
    throw std::out_of_range("La pila está vacía.");
}

// Verificar si la pila está vacía
bool StackList::empty() const {
    return size == 0;
}

// Obtener el tamaño actual de la pila
int StackList::get_size() const {
    return size;
}
