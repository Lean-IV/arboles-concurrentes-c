#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "utilArbol.h"


void llenarArbol(int tam, ArbolPtr arbol) {
    if (tam <= 0 || arbol == NULL) return;

    bool* usado = calloc(tam * 10, sizeof(bool));
    srand((unsigned)time(NULL));

    int count = 0;
    while (count < tam) {
        int num = rand() % (tam * 10);
        if (!usado[num]) {
            insertar(arbol, num);
            usado[num] = true;
            count++;
        }
    }
    free(usado);
}

void tareaPesada(int valor){
    double resultado = 0;
    for (int i = 0; i < 100000; i++) {
        resultado += sin(valor) * cos(valor);
    }
}
