#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

// Estructura para representar a un cliente
struct cliente {
    std::string nombre;      // Nombre del cliente
    std::string rut;         // RUT del cliente (identificación)
    int nivel_prioridad;     // Nivel de prioridad (1 = Muy grave, 4 = Leve)

    // Constructor para inicializar los datos del cliente
    cliente(std::string n, std::string r, int nivel)
        : nombre(n), rut(r), nivel_prioridad(nivel) {}
};

#endif // CLIENTE_HPP
