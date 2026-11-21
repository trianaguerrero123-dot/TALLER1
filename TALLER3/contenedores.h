
#ifndef CONTENEDORES_H
#define CONTENEDORES_H

typedef struct Contenedor {
    int id;
    float tara;
    float carga;
    float total;
    float costo;
    struct Contenedor *anterior;
    struct Contenedor *siguiente;
} Contenedor;

void insertarContenedor(void);
void buscarContenedor(void);
void actualizarContenedor(void);
void eliminarContenedor(void);
void mostrarAdelante(void);
void mostrarAtras(void);
void liberarMemoria(void);

#endif
