#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "ordenamiento.h"

int main(void) {
    Carga *cargas = NULL;
    int cantidad = 0;
    int opcion;
    int metodo;
    int orden;
    Carga *temporal;

    do {
        printf("\n===========================================\n");
        printf(" SISTEMA DE CARGAS - PUERTO DE BUENAVENTURA\n");
        printf("===========================================\n");
        printf("1. Registrar una carga\n");
        printf("2. Mostrar cargas\n");
        printf("3. Ordenar cargas por peso\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Opcion no valida. Intente nuevamente.\n");
            while (getchar() != '\n') { }
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                temporal = realloc(cargas, (cantidad + 1) * sizeof(Carga));
                if (temporal == NULL) {
                    printf("No se pudo reservar memoria.\n");
                    free(cargas);
                    return 1;
                }

                cargas = temporal;
                printf("\n--- Registro de carga ---\n");
                registrarCarga(&cargas[cantidad]);
                cantidad++;
                printf("Carga registrada correctamente.\n");
                break;

            case 2:
                mostrarCargas(cargas, cantidad);
                break;

            case 3:
                if (cantidad < 2) {
                    printf("Registre al menos dos cargas para ordenarlas.\n");
                    break;
                }

                printf("\nMetodo de ordenamiento:\n");
                printf("1. Bubble Sort (burbuja)\n");
                printf("2. Selection Sort (seleccion)\n");
                printf("3. Insertion Sort (insercion)\n");
                printf("Seleccione el metodo: ");
                if (scanf("%d", &metodo) != 1) {
                    printf("Metodo no valido.\n");
                    while (getchar() != '\n') { }
                    break;
                }

                printf("Orden: 1. Menor a mayor  2. Mayor a menor: ");
                if (scanf("%d", &orden) != 1 || (orden != 1 && orden != 2)) {
                    printf("Orden no valido.\n");
                    while (getchar() != '\n') { }
                    break;
                }

                if (metodo == 1) {
                    bubbleSort(cargas, cantidad, orden == 1);
                } else if (metodo == 2) {
                    selectionSort(cargas, cantidad, orden == 1);
                } else if (metodo == 3) {
                    insertionSort(cargas, cantidad, orden == 1);
                } else {
                    printf("Metodo no valido.\n");
                    break;
                }

                printf("Cargas ordenadas correctamente.\n");
                mostrarCargas(cargas, cantidad);
                break;

            case 4:
                printf("Saliendo del programa. Hasta luego.\n");
                break;

            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 4);

    free(cargas);
    return 0;
}
