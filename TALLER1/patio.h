#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD 5

typedef struct {
    Contenedor contenedores[CAPACIDAD];
    int cantidad;
} Patio;

void inicializarPatio(Patio *patio);
int insertarContenedor(Patio *patio, Contenedor c);
int buscarContenedor(Patio *patio, char codigo[]);
int retirarContenedor(Patio *patio);
void mostrarPatio(Patio *patio);

#endif
