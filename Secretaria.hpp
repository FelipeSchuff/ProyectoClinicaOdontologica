#ifndef SECRETARIA_HPP
#define SECRETARIA_HPP

#include <iostream>
#include <string>

struct Secretaria {
    std::string nombre;      // Nombre de la secretaria
    int hora_entrada;        // Hora de entrada (en formato 24 horas)
    int minuto_entrada;      // Minutos de entrada
    int hora_salida;         // Hora de salida (en formato 24 horas)
    int minuto_salida;       // Minutos de salida

    // Constructor para inicializar los datos de la secretaria
    Secretaria(std::string n, int hE, int mE, int hS, int mS) 
        : nombre(n), hora_entrada(hE), minuto_entrada(mE), hora_salida(hS), minuto_salida(mS) {}

    // Método para obtener la hora de entrada
    std::string obtenerHoraEntrada() {
        return std::to_string(hora_entrada) + ":" + (minuto_entrada < 10 ? "0" : "") + std::to_string(minuto_entrada);
    }

    // Método para obtener la hora de salida
    std::string obtenerHoraSalida() {
        return std::to_string(hora_salida) + ":" + (minuto_salida < 10 ? "0" : "") + std::to_string(minuto_salida);
    }

    // Método para calcular las horas trabajadas
    float horasTrabajadas() {
        int totalMinutosEntrada = hora_entrada * 60 + minuto_entrada;
        int totalMinutosSalida = hora_salida * 60 + minuto_salida;

        // Si la salida es al día siguiente
        if (totalMinutosSalida < totalMinutosEntrada) {
            totalMinutosSalida += 24 * 60;
        }

        int totalMinutosTrabajados = totalMinutosSalida - totalMinutosEntrada;
        return static_cast<float>(totalMinutosTrabajados) / 60.0; // De minutos a horas
    }

    // Método para mostrar la información de las horas trabajadas
    void mostrarHorasTrabajadas() {
        float horas = horasTrabajadas();
        int horasInt = static_cast<int>(horas);
        int minutosInt = static_cast<int>((horas - horasInt) * 60);

        std::cout << "Secretaria: " << nombre << "\n"
                  << "Hora de entrada: " << obtenerHoraEntrada() << "\n"
                  << "Hora de salida: " << obtenerHoraSalida() << "\n"
                  << "Trabajó " << horasInt << " horas y " << minutosInt << " minutos." << std::endl;
    }
};

#endif // SECRETARIA_HPP