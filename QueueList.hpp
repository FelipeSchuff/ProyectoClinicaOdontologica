#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP

#include "Cliente.hpp"  // Incluir la estructura cliente

// Nodo para la cola
struct QueueNode {
    QueueNode* next;
    cliente data;
    QueueNode(cliente c) : data(c), next(nullptr) {}
};

// Clase para la Cola
class QueueList {
private:
    QueueNode* frontNode;
    QueueNode* rearNode;
    int size;

public:
    QueueList();                           // Constructor
    ~QueueList();                          // Destructor
    void enqueue(cliente c);               // Encolar un cliente
    void enqueue_prioritario(cliente c);   // Encolar con prioridad
    void dequeue();                        // Desencolar el primer elemento
    cliente front() const;                 // Obtener el elemento al frente
    bool empty() const;                    // Verificar si está vacía
    int get_size() const;                  // Obtener el tamaño de la cola
    QueueNode* get_front_node() const;     // Acceder a los nodos directamente
};

#endif // QUEUELIST_HPP
