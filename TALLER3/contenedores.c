
#include <stdio.h>
#include <stdlib.h>
#include "contenedores.h"

Contenedor *inicio = NULL;
Contenedor *fin = NULL;
int siguienteID = 1;

Contenedor *buscarPorID(int id) {
    Contenedor *actual = inicio;

    while (actual != NULL) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

void mostrarDatos(Contenedor *c) {
    printf("\nID: %d\n", c->id);
    printf("Tara: %.2f\n", c->tara);
    printf("Carga: %.2f\n", c->carga);
    printf("Peso total: %.2f\n", c->total);
    printf("Costo: %.2f\n", c->costo);
}

void insertarContenedor(void) {
    Contenedor *nuevo;

    nuevo = malloc(sizeof(Contenedor));

    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }

    nuevo->id = siguienteID++;

    printf("Ingrese la tara: ");
    scanf("%f", &nuevo->tara);

    printf("Ingrese el peso de carga: ");
    scanf("%f", &nuevo->carga);

    printf("Ingrese el costo: ");
    scanf("%f", &nuevo->costo);

    nuevo->total = nuevo->tara + nuevo->carga;

    nuevo->anterior = fin;
    nuevo->siguiente = NULL;

    if (inicio == NULL) {
        inicio = nuevo;
        fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }

    printf("Contenedor registrado. ID: %d\n", nuevo->id);
}

void buscarContenedor(void) {
    int id;

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    Contenedor *c = buscarPorID(id);

    if (c == NULL) {
        printf("Contenedor no encontrado.\n");
    } else {
        mostrarDatos(c);
    }
}

void actualizarContenedor(void) {
    int id;

    printf("Ingrese el ID que desea actualizar: ");
    scanf("%d", &id);

    Contenedor *c = buscarPorID(id);

    if (c == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    printf("Nueva tara: ");
    scanf("%f", &c->tara);

    printf("Nueva carga: ");
    scanf("%f", &c->carga);

    printf("Nuevo costo: ");
    scanf("%f", &c->costo);

    c->total = c->tara + c->carga;

    printf("Contenedor actualizado.\n");
}

void eliminarContenedor(void) {
    int id;

    printf("Ingrese el ID que desea eliminar: ");
    scanf("%d", &id);

    Contenedor *c = buscarPorID(id);

    if (c == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    if (c->anterior != NULL) {
        c->anterior->siguiente = c->siguiente;
    } else {
        inicio = c->siguiente;
    }

    if (c->siguiente != NULL) {
        c->siguiente->anterior = c->anterior;
    } else {
        fin = c->anterior;
    }

    free(c);

    printf("Contenedor eliminado.\n");
}

void mostrarAdelante(void) {
    Contenedor *actual = inicio;

    while (actual != NULL) {
        mostrarDatos(actual);
        actual = actual->siguiente;
    }
}

void mostrarAtras(void) {
    Contenedor *actual = fin;

    while (actual != NULL) {
        mostrarDatos(actual);
        actual = actual->anterior;
    }
}

void liberarMemoria(void) {
    Contenedor *actual = inicio;

    while (actual != NULL) {
        Contenedor *temporal = actual;
        actual = actual->siguiente;
        free(temporal);
    }

    inicio = NULL;
    fin = NULL;
}
