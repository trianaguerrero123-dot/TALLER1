#include <stdio.h>
#include <string.h>
#include "patio.h"

void inicializarPatio(Patio *patio) {
    patio->cantidad = 0;
}

int insertarContenedor(Patio *patio, Contenedor c) {
    if (patio->cantidad >= CAPACIDAD) {
        return 0;
    }

    patio->contenedores[patio->cantidad] = c;
    patio->cantidad++;

    return 1;
}

int buscarContenedor(Patio *patio, char codigo[]) {
    int i;

    for (i = 0; i < patio->cantidad; i++) {
        if (strcmp(patio->contenedores[i].codigo, codigo) == 0) {
            return i;
        }
    }

    return -1;
}

int retirarContenedor(Patio *patio) {
    int i;

    if (patio->cantidad == 0) {
        return 0;
    }

    /* Politica FIFO: sale primero el contenedor que entro primero. */
    for (i = 0; i < patio->cantidad - 1; i++) {
        patio->contenedores[i] = patio->contenedores[i + 1];
    }

    patio->cantidad--;

    return 1;
}

void mostrarPatio(Patio *patio) {
    int i;

    if (patio->cantidad == 0) {
        printf("\nEl patio esta vacio.\n");
        return;
    }

    printf("\n--- CONTENEDORES EN EL PATIO ---\n");

    for (i = 0; i < patio->cantidad; i++) {
        printf("%d. ", i + 1);
        mostrarContenedor(patio->contenedores[i]);
    }
}
