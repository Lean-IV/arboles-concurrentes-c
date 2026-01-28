#ifndef UTILARBOL_H_INCLUDED
#define UTILARBOL_H_INCLUDED

#include "arbol.h"

/**
 * Llena el árbol con 'tam' valores aleatorios.
 * pre: tam > 0, arbol ≠ NULL
 * post: El árbol contiene 'tam' nuevos valores insertados.
 */
void llenarArbol(int tam, ArbolPtr arbol);

/**
 * Simula una tarea costosa usando un valor como entrada.
 * pre: valor entero válido.
 * post: Se consume tiempo de CPU de forma artificial.
 */
void tareaPesada(int valor);

#endif // UTILARBOL_H_INCLUDED
