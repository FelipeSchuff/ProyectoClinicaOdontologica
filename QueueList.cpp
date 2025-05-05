#include "QueueList.hpp"
#include <iostream>

// Constructor
QueueList::QueueList() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// Destructor
QueueList::~QueueList() {
    while (!empty()) {
        dequeue();
    }
}

// Método para insertar un cliente según prioridad
void QueueList::enqueue_prioritario(cliente c) {
    QueueNode* newNode = new QueueNode(c);

    if (empty() || c.nivel_prioridad < frontNode->data.nivel_prioridad) {
        // Insertar al frente si está vacío o si tiene mayor prioridad
        newNode->next = frontNode;
        frontNode = newNode;
        if (!rearNode) rearNode = newNode; // Actualizar rear si era la primera inserción
    } else {
        // Insertar en la posición correcta según prioridad
        QueueNode* current = frontNode;
        while (current->next && current->next->data.nivel_prioridad <= c.nivel_prioridad) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) rearNode = newNode; // Actualizar rear si está al final
    }
    size++;
}

// Método para insertar un cliente al final de la cola
void QueueList::enqueue(cliente c) {
    QueueNode* newNode = new QueueNode(c);
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;
}

// Método para eliminar el primer cliente de la cola
void QueueList::dequeue() {
    if (empty()) {
        std::cerr << "La cola está vacía.\n";
        return;
    }
    QueueNode* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    if (!frontNode) rearNode = nullptr; // Si la cola quedó vacía
    size--;
}

// Obtener el cliente al frente de la cola
cliente QueueList::front() const {
    if (empty()) {
        throw std::runtime_error("La cola está vacía.");
    }
    return frontNode->data;
}

// Verificar si la cola está vacía
bool QueueList::empty() const {
    return frontNode == nullptr;
}

// Obtener el tamaño de la cola
int QueueList::get_size() const {
    return size;
}

// Obtener el nodo al frente
QueueNode* QueueList::get_front_node() const {
    return frontNode;
}
