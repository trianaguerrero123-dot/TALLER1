
#include <stdio.h>
#include "contenedores.h"

int main(void) {
    int opcion;

    do {
        printf("\n===== SISTEMA DE CONTENEDORES =====\n");
        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar hacia adelante\n");
        printf("6. Mostrar hacia atras\n");
        printf("7. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                insertarContenedor();
                break;

            case 2:
                buscarContenedor();
                break;

            case 3:
                actualizarContenedor();
                break;

            case 4:
                eliminarContenedor();
                break;

            case 5:
                mostrarAdelante();
                break;

            case 6:
                mostrarAtras();
                break;

            case 7:
                liberarMemoria();
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcion incorrecta.\n");
        }

    } while (opcion != 7);

    return 0;
}
