TALLER 1 - PROGRAMACION MODULAR

Proyecto basico para gestionar un patio de contenedores.

ARCHIVOS:
- contenedor.h: define la estructura Contenedor y el prototipo de mostrarContenedor.
- contenedor.c: implementa mostrarContenedor.
- patio.h: define la estructura Patio, capacidad y prototipos.
- patio.c: implementa insertar, buscar, retirar y mostrar.
- main.c: contiene el menu principal.

ESTRUCTURA ELEGIDA:
Se utiliza una cola sencilla con politica FIFO.
FIFO significa First In, First Out: el primero que entra es el primero que sale.

CAPACIDAD:
El patio permite maximo 5 contenedores.

COMPILACION:
gcc -c contenedor.c -o contenedor.o
gcc -c patio.c -o patio.o
gcc -c main.c -o main.o
gcc contenedor.o patio.o main.o -o puerto_manager.exe

EJECUCION EN WINDOWS:
puerto_manager.exe

EJECUCION EN LINUX/MAC:
./puerto_manager
