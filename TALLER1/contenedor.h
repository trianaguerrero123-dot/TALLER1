#ifndef CONTENEDOR_H
#define CONTENEDOR_H

typedef struct {
    char codigo[5];
    float peso;
    char tipo[30];
} Contenedor;

void mostrarContenedor(Contenedor c);

#endif
