🦷 Dental Clinic - Patient Management System in C++

This project simulates the basic operation of a dental clinic using data structures in C++. It allows for patient registration, assigning priorities, attending clients, and calculating the dentist's salary based on the treated cases.
📚 Description

Several custom data structures are implemented:

    QueueList: Queue of patients based on arrival order.

    StackList: Temporary stack used to reorder clients.

    ListaDoblementeEnlazadaCliente: Doubly linked list of treated patients.

    Dentist: Calculates salary based on the urgency of cases.

    Secretary: Manages appointment scheduling.

🏥 Main Features

    Register a new patient with name, ID (RUT), and urgency level.

    Organize patients by priority:

        1: Toothache (Very severe)

        2: Lost tooth (Severe)

        3: Cavities (Moderate)

        4: Tooth sensitivity (Mild)

    Attend patients and compute the dentist’s salary.

    Display the list of patients who have been attended.

🧱 Code Structure

    Cliente.hpp: Defines the patient structure.

    Dentista.hpp: Dentist logic and salary calculation.

    List.hpp & List.cpp: Doubly linked list for attended patients.

    main.cpp: Main controller for the system.

    QueueList.*, StackList.*, Secretaria.*: Other supporting data structures.

⚙️ Compilation

To compile the program, make sure to include all relevant .cpp files:

g++ main.cpp List.cpp QueueList.cpp StackList.cpp Secretaria.cpp -o clinic.exe QueueList.cpp StackList.cpp Secretaria.cpp -o clinic.exe

-Español
# 🦷 Clínica Odontológica - Sistema de Gestión de Pacientes en C++

Este proyecto simula el funcionamiento básico de una clínica odontológica utilizando estructuras de datos en C++. Permite registrar pacientes, asignar prioridades, atender clientes y calcular el sueldo del dentista según los casos tratados.

## 📚 Descripción

Se implementan diversas estructuras:

- `QueueList`: Cola de pacientes por orden de llegada.
- `StackList`: Pila temporal para reordenar clientes.
- `ListaDoblementeEnlazadaCliente`: Lista de clientes atendidos.
- `Dentista`: Calcula sueldo en base a prioridad de atención.
- `Secretaria`: Administra horarios de atención.

## 🏥 Funcionalidades principales

- Registrar un nuevo cliente con nombre, RUT y nivel de urgencia.
- Organizar clientes por prioridad:
  - 1: Dolor de muelas (Muy grave)
  - 2: Pérdida de diente (Grave)
  - 3: Caries (Moderado)
  - 4: Sensibilidad dental (Leve)
- Atender clientes y calcular sueldo del dentista.
- Mostrar lista de pacientes ya atendidos.

## 🧱 Estructura del código

- `Cliente.hpp`: Define estructura del cliente.
- `Dentista.hpp`: Lógica del dentista.
- `List.hpp` y `List.cpp`: Lista doblemente enlazada de clientes atendidos.
- `main.cpp`: Control principal del sistema.
- `QueueList.*`, `StackList.*`, `Secretaria.*`: Otras estructuras.

## ⚙️ Compilación

Para compilar el programa, asegúrate de incluir todos los archivos `.cpp` relevantes:

```bash
g++ main.cpp List.cpp QueueList.cpp StackList.cpp Secretaria.cpp -o clinica.exe