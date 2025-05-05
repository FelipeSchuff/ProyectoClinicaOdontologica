#ifndef DENTISTA_HPP
#define DENTISTA_HPP

#include <string>

// Estructura para representar a un dentista
struct Dentista {
    std::string nombre;          // Nombre del dentista
    int pacientes_atendidos;     // Número de pacientes atendidos
    double sueldo;               // Sueldo acumulado del dentista

    // Constructor para inicializar al dentista
    Dentista(std::string n) : nombre(n), pacientes_atendidos(0), sueldo(0.0) {}

    // Calcula el sueldo basado en la prioridad del paciente
    void calcularSueldo(int prioridad) {
        double pago_por_paciente = 100.0; // Pago base por paciente
        sueldo += pago_por_paciente * (5 - prioridad); // Más prioridad, más paga
    }
};

#endif // DENTISTA_HPP
