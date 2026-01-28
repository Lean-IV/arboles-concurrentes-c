#include <stdlib.h>
#include <stdio.h>

#include "arbol.h"

struct Arbol {
    int dato;
    ArbolPtr izq;
    ArbolPtr der;
};

ArbolPtr crearArbol(int dato) {
    ArbolPtr a = malloc(sizeof(struct Arbol));
    a->dato = dato;
    a->izq = NULL;
    a->der = NULL;
    return a;
}

void insertar(ArbolPtr arbol, int dato) {
    if (arbol->dato < dato) {
        if (arbol->der == NULL)
            arbol->der = crearArbol(dato);
        else
            insertar(arbol->der, dato);
    } else {
        if (arbol->izq == NULL)
            arbol->izq = crearArbol(dato);
        else
            insertar(arbol->izq, dato);
    }
}

/// Getters
int obtenerDato(ArbolPtr arbol) {
    return arbol->dato;
}

ArbolPtr obtenerIzq(ArbolPtr arbol) {
    return arbol->izq;
}

ArbolPtr obtenerDer(ArbolPtr arbol) {
    return arbol->der;
}

/// Setters
void setDato(ArbolPtr arbol, int dato) {
    arbol->dato = dato;
}

void setIzq(ArbolPtr arbol, ArbolPtr izq) {
    arbol->izq = izq;
}

void setDer(ArbolPtr arbol, ArbolPtr der) {
    arbol->der = der;
}


void preOrder(ArbolPtr arbol) {
    if (arbol != NULL) {
        tareaPesada(obtenerDato(arbol));
        preOrder(obtenerIzq(arbol));
        preOrder(obtenerDer(arbol));
    }
}

void inOrder(ArbolPtr arbol) {
    if (arbol != NULL) {
        inOrder(obtenerIzq(arbol));
        tareaPesada(obtenerDato(arbol));
        inOrder(obtenerDer(arbol));
    }
}

void postOrder(ArbolPtr arbol) {
    if (arbol != NULL) {
        postOrder(obtenerIzq(arbol));
        postOrder(obtenerDer(arbol));
        tareaPesada(obtenerDato(arbol));
    }
}
