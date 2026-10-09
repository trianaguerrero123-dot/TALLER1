#include <stdio.h>
#include "contenedor.h"

void mostrarContenedor(Contenedor c) {
    printf("Codigo: %s | Peso: %.2f toneladas | Tipo: %s\n",
           c.codigo, c.peso, c.tipo);
}
