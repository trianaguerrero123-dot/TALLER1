#include "ordenamiento.h"

static int debeIntercambiar(float a, float b, int ascendente) {
    if (ascendente) {
        return a > b;
    }
    return a < b;
}

void bubbleSort(Carga *cargas, int cantidad, int ascendente) {
    int i, j;
    Carga temporal;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - i - 1; j++) {
            if (debeIntercambiar(cargas[j].peso, cargas[j + 1].peso, ascendente)) {
                temporal = cargas[j];
                cargas[j] = cargas[j + 1];
                cargas[j + 1] = temporal;
            }
        }
    }
}

void selectionSort(Carga *cargas, int cantidad, int ascendente) {
    int i, j, posicion;
    Carga temporal;

    for (i = 0; i < cantidad - 1; i++) {
        posicion = i;

        for (j = i + 1; j < cantidad; j++) {
            if (debeIntercambiar(cargas[posicion].peso, cargas[j].peso, ascendente)) {
                posicion = j;
            }
        }

        if (posicion != i) {
            temporal = cargas[i];
            cargas[i] = cargas[posicion];
            cargas[posicion] = temporal;
        }
    }
}

void insertionSort(Carga *cargas, int cantidad, int ascendente) {
    int i, j;
    Carga actual;

    for (i = 1; i < cantidad; i++) {
        actual = cargas[i];
        j = i - 1;

        while (j >= 0 && debeIntercambiar(cargas[j].peso, actual.peso, ascendente)) {
            cargas[j + 1] = cargas[j];
            j--;
        }

        cargas[j + 1] = actual;
    }
}
