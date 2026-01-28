#ifndef ARBOLCONCURRENTE_H_INCLUDED
#define ARBOLCONCURRENTE_H_INCLUDED

#include "arbol.h"
#include "utilArbol.h"

/**
 * Recorre el árbol en preorden usando concurrencia.
 * pre: arbol puede ser NULL.
 * post: Se recorren los nodos en preorden usando múltiples hilos.
 */
void preOrderConcurrente(ArbolPtr arbol);

/**
 * Recorre el árbol en inorden usando concurrencia.
 * pre: arbol puede ser NULL.
 * post: Se recorren los nodos en inorden usando múltiples hilos.
 */
void inOrderConcurrente(ArbolPtr arbol);

/**
 * Recorre el árbol en postorden usando concurrencia.
 * pre: arbol puede ser NULL.
 * post: Se recorren los nodos en postorden usando múltiples hilos.
 */
void postOrderConcurrente(ArbolPtr arbol);

#endif // ARBOLCONCURRENTE_H_INCLUDED
