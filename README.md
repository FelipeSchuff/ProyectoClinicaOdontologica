# Clínica Odontológica - Sistema de Gestión de Pacientes en C++

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
