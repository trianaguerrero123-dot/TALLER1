#ifndef CARGA_H
#define CARGA_H

#define MAX_CODIGO 30
#define MAX_MERCANCIA 50
#define MAX_BAHIA 20

typedef struct {
    char codigo[MAX_CODIGO];
    float peso;
    char mercancia[MAX_MERCANCIA];
    char bahia[MAX_BAHIA];
} Carga;

void registrarCarga(Carga *carga);
void mostrarCargas(const Carga *cargas, int cantidad);

#endif
