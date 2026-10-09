#include <stdio.h>
#include "patio.h"

int main() {
    Patio patio;
    Contenedor c;
    char codigo[5];
    int opcion;
    int posicion;

    inicializarPatio(&patio);

    do {
        printf("\n===== PUERTO MANAGER =====\n");
        printf("1. Registrar contenedor\n");
        printf("2. Mostrar contenedores\n");
        printf("3. Buscar contenedor\n");
        printf("4. Retirar primer contenedor (FIFO)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                if (patio.cantidad >= CAPACIDAD) {
                    printf("\nEl patio esta lleno. No se puede ingresar otro contenedor.\n");
                    break;
                }

                printf("\nIngrese codigo de 4 caracteres: ");
                scanf("%4s", c.codigo);

                printf("Ingrese peso en toneladas: ");
                scanf("%f", &c.peso);

                printf("Ingrese tipo de mercancia: ");
                scanf("%29s", c.tipo);

                if (insertarContenedor(&patio, c)) {
                    printf("\nContenedor registrado correctamente.\n");
                }
                break;

            case 2:
                mostrarPatio(&patio);
                break;

            case 3:
                printf("\nIngrese el codigo a buscar: ");
                scanf("%4s", codigo);

                posicion = buscarContenedor(&patio, codigo);

                if (posicion != -1) {
                    printf("\nContenedor encontrado:\n");
                    mostrarContenedor(patio.contenedores[posicion]);
                } else {
                    printf("\nEl contenedor no fue encontrado.\n");
                }
                break;

            case 4:
                if (retirarContenedor(&patio)) {
                    printf("\nSe retiro el primer contenedor registrado.\n");
                } else {
                    printf("\nEl patio esta vacio.\n");
                }
                break;

            case 5:
                printf("\nPrograma finalizado.\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}
