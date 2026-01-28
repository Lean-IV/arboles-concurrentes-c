#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct Arbol;

typedef struct Arbol* ArbolPtr;

/**
 * Crea un nuevo nodo con el dato proporcionado.
 * pre: -
 * post: Devuelve un nuevo nodo con el valor: "int dato", "hijos NULL".
 */
ArbolPtr crearArbol(int dato);

/**
 * Inserta un dato en el árbol respetando el orden binario.
 * pre: arbol ≠ NULL
 * post: El árbol contiene el nuevo dato en la posición correcta.
 */
void insertar(ArbolPtr arbol, int dato);

/// Getters

/**
 * Devuelve el dato almacenado en el nodo.
 * pre: arbol ≠ NULL
 * post: Devuelve un entero.
 */
int obtenerDato(ArbolPtr arbol);

/**
 * Devuelve el hijo izquierdo del nodo.
 * pre: arbol ≠ NULL
 * post: Devuelve un puntero (puede ser NULL).
 */
ArbolPtr obtenerIzq(ArbolPtr arbol);

/**
 * Devuelve el hijo derecho del nodo.
 * pre: arbol ≠ NULL
 * post: Devuelve un puntero (puede ser NULL).
 */
ArbolPtr obtenerDer(ArbolPtr arbol);

/// Setters

/**
 * Asigna un nuevo valor al nodo.
 * pre: arbol ≠ NULL
 * post: El nodo contiene el nuevo dato.
 */
void setDato(ArbolPtr arbol, int dato);

/**
 * Asigna un hijo izquierdo al nodo.
 * pre: arbol ≠ NULL
 * post: El hijo izquierdo apunta al nuevo subárbol.
 */
void setIzq(ArbolPtr arbol, ArbolPtr izq);

/**
 * Asigna un hijo derecho al nodo.
 * pre: arbol ≠ NULL
 * post: El hijo derecho apunta al nuevo subárbol.
 */
void setDer(ArbolPtr arbol, ArbolPtr der);

/// Recorridos secuenciales

/**
 * Recorre el árbol en preorden, ejecutando tareaPesada() en cada nodo.
 * pre: Puede ser NULL.
 * post: Se visitan todos los nodos en orden preorden.
 */
void preOrder(ArbolPtr arbol);

/**
 * Recorre el árbol en inorden, ejecutando tareaPesada() en cada nodo.
 * pre: Puede ser NULL.
 * post: Se visitan todos los nodos en orden inorden.
 */
void inOrder(ArbolPtr arbol);

/**
 * Recorre el árbol en postorden, ejecutando tareaPesada() en cada nodo.
 * pre: Puede ser NULL.
 * post: Se visitan todos los nodos en orden postorden.
 */
void postOrder(ArbolPtr arbol);

#endif // ARBOL_H_INCLUDED
