#include <iostream>
#include <string>
#include "QueueList.hpp"      // Biblioteca para manejar la cola (Queue)
#include "StackList.hpp"      // Biblioteca para manejar el stack (pila)
#include "Cliente.hpp"        // Clase Cliente que define los atributos de un cliente
#include "List.hpp"           // Biblioteca para manejar listas (doblemente enlazadas)
#include "Dentista.hpp"       // Clase Dentista para manejar información del dentista
#include "Secretaria.hpp"     // Clase Secretaria para manejar información de la secretaria

// Crear las estructuras principales que se usarán
QueueList fila_clientes;             // Cola principal para clientes registrados
StackList stack_temporal;           // Pila para clientes no atendidos temporalmente
QueueList fila_ordenada;            // Cola para clientes ordenados por prioridad
ListaDoblementeEnlazadaCliente clientes_atendidos; // Lista para clientes que ya han sido atendidos
Dentista dentista("Dr. Gonzalez");  // Crear un dentista con su nombre
Secretaria secretaria("Ana Perez", 8, 0, 17, 0); // Crear una secretaria con su nombre y horario

// Función para ingresar un nuevo cliente con su nivel de prioridad
void ingresar_cliente() {
    std::string nombre, rut;
    int nivel_prioridad;

    // Pedir nombre y RUT del cliente
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese su RUT: ";
    std::cin >> rut;

    // Pedir nivel de prioridad
    std::cout << "Seleccione el nivel de prioridad:\n";
    std::cout << "1. Dolor de muelas (Muy grave)\n";
    std::cout << "2. Pérdida de diente (Grave)\n";
    std::cout << "3. Caries (Moderado)\n";
    std::cout << "4. Sensibilidad dental (Leve)\n";
    std::cout << "Opcion: ";
    std::cin >> nivel_prioridad;

    // Validar si el nivel de prioridad es válido
    if (nivel_prioridad < 1 || nivel_prioridad > 4) {
        std::cout << "Nivel de prioridad invalido.\n";
        return;
    }

    // Crear un cliente nuevo y agregarlo a la cola principal
    cliente nuevo_cliente(nombre, rut, nivel_prioridad);
    fila_clientes.enqueue(nuevo_cliente);
}

// Función para ordenar los clientes según su prioridad y moverlos entre las estructuras
void ordenar_clientes() {
    int iterador = 1;

    // Mientras haya clientes en la cola principal o en la pila temporal
    while (!fila_clientes.empty() || !stack_temporal.empty()) {
        if (!fila_clientes.empty()) {
            cliente actual = fila_clientes.front(); // Obtener el cliente de la frente de la cola
            fila_clientes.dequeue(); // Eliminarlo de la cola principal

            // Si el cliente tiene la prioridad que buscamos, lo agregamos a la cola ordenada
            if (actual.nivel_prioridad == iterador) {
                fila_ordenada.enqueue(actual);
            } else {
                // Si no, lo pasamos a la pila temporal
                stack_temporal.push(actual);
            }
        }

        // Si ya no hay clientes en la cola pero hay en la pila, los movemos de vuelta a la cola
        if (fila_clientes.empty() && !stack_temporal.empty()) {
            while (!stack_temporal.empty()) {
                cliente temp = stack_temporal.top();
                stack_temporal.pop();
                fila_clientes.enqueue(temp);
            }
        }

        iterador++; // Aumentar el nivel de prioridad
    }
}

// Función para atender al primer cliente en la cola ordenada
void atender_cliente() {
    if (fila_ordenada.empty()) {
        std::cout << "No hay clientes para atender.\n";
        return;
    }

    cliente atendido = fila_ordenada.front(); // Obtener el cliente de la frente de la cola ordenada
    fila_ordenada.dequeue(); // Eliminarlo de la cola ordenada
    clientes_atendidos.insertarAtras(atendido); // Agregarlo a la lista de atendidos

    // Actualizar información del dentista
    dentista.pacientes_atendidos++;
    dentista.calcularSueldo(atendido.nivel_prioridad);

    // Mostrar la información del cliente atendido
    std::cout << "Atendiendo a: " << atendido.nombre << "\n";
    std::cout << "RUT: " << atendido.rut << "\n";
    std::cout << "Prioridad: " << atendido.nivel_prioridad << "\n";
}

// Función para mostrar la lista de clientes que ya han sido atendidos
void mostrar_clientes_atendidos() {
    std::cout << "Clientes atendidos:\n";
    clientes_atendidos.imprimirListaIzqDer(); // Imprimir la lista de clientes atendidos
}

// Función para mostrar la información de la secretaria
void mostrar_info_secretaria() {
    secretaria.mostrarHorasTrabajadas(); // Mostrar el horario trabajado de la secretaria
}

// Menú principal del programa
int main() {
    int opcion;

    do {
        std::cout << "----- Menu -----\n";
        std::cout << "1. Ingresar cliente\n";
        std::cout << "2. Atender cliente\n";
        std::cout << "3. Mostrar clientes atendidos\n";
        std::cout << "4. Ver sueldo del dentista\n";
        std::cout << "5. Ver información de la secretaria\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            ingresar_cliente();  // Llamar a la función para ingresar un cliente
            break;
        case 2:
            ordenar_clientes();  // Ordenar los clientes y moverlos entre estructuras
            atender_cliente();   // Atender al primer cliente
            break;
        case 3:
            mostrar_clientes_atendidos();  // Mostrar los clientes que ya han sido atendidos
            break;
        case 4:
            std::cout << "Dentista: " << dentista.nombre << "\n";
            std::cout << "Pacientes atendidos: " << dentista.pacientes_atendidos << "\n";
            std::cout << "Sueldo: $" << dentista.sueldo << "\n";  // Mostrar información del dentista
            break;
        case 5:
            mostrar_info_secretaria();  // Mostrar la información de la secretaria
            break;
        case 6:
            std::cout << "Saliendo...\n";  // Salir del programa
            break;
        default:
            std::cout << "Opción inválida.\n";  // Mostrar mensaje si la opción no es válida
        }
    } while (opcion != 6);  // Continuar hasta que se elija salir

    return 0;
}
