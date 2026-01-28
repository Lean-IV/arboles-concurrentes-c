#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arbol.h"
#include "utilArbol.h"

int main() {
    int tam = 10; /// Tamaño del árbol
    printf("Llenando arbol con %d numeros aleatorios...\n", tam);

    /// Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    /// Crear el árbol con una raíz inicial aleatoria
    ArbolPtr a = crearArbol(rand() % (tam * 10));
    llenarArbol(tam - 1, a); // -1 porque ya insertamos uno como raíz

    clock_t start, end;

    // -------------------------------
    /// PreOrder Secuencial
    // -------------------------------
    printf("\nPreOrder\n");
    start = clock();
    preOrder(a);
    end = clock();
    printf("\nTiempo preOrder: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------
    /// PreOrder Concurrente
    // -------------------------------
    printf("\nPreOrder Concurrente\n");
    start = clock();
    preOrderConcurrente(a);
    end = clock();
    printf("\nTiempo preOrderConcurrente: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------
    /// InOrder Secuencial
    // -------------------------------
    printf("\nInOrder\n");
    start = clock();
    inOrder(a);
    end = clock();
    printf("\nTiempo inOrder: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------
    /// InOrder Concurrente
    // -------------------------------
    printf("\nInOrder Concurrente\n");
    start = clock();
    inOrderConcurrente(a);
    end = clock();
    printf("\nTiempo inOrderConcurrente: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------
    /// PostOrder Secuencial
    // -------------------------------
    printf("\nPostOrder\n");
    start = clock();
    postOrder(a);
    end = clock();
    printf("\nTiempo postOrder: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // -------------------------------
    /// PostOrder Concurrente
    // -------------------------------
    printf("\nPostOrder Concurrente\n");
    start = clock();
    postOrderConcurrente(a);
    end = clock();
    printf("\nTiempo postOrderConcurrente: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
