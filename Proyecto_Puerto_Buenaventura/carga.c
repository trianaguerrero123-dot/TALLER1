#include <stdio.h>
#include "carga.h"

void registrarCarga(Carga *carga) {
    printf("Codigo unico (sin espacios): ");
    scanf("%29s", carga->codigo);

    printf("Peso en toneladas: ");
    while (scanf("%f", &carga->peso) != 1 || carga->peso < 0) {
        printf("Ingrese un peso valido (numero mayor o igual a cero): ");
        while (getchar() != '\n') { }
    }

    printf("Tipo de mercancia (sin espacios, puede usar guion bajo): ");
    scanf("%49s", carga->mercancia);

    printf("Bahia asignada: ");
    scanf("%19s", carga->bahia);
}

void mostrarCargas(const Carga *cargas, int cantidad) {
    int i;

    if (cantidad == 0) {
        printf("\nNo hay cargas registradas.\n");
        return;
    }

    printf("\n%-5s %-18s %-15s %-22s %-12s\n",
           "No.", "Codigo", "Peso (ton)", "Mercancia", "Bahia");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < cantidad; i++) {
        printf("%-5d %-18s %-15.2f %-22s %-12s\n",
               i + 1, cargas[i].codigo, cargas[i].peso,
               cargas[i].mercancia, cargas[i].bahia);
    }
}
