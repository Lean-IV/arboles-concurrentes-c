#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

#include "arbol.h"

#include <windows.h>

int obtenerCantidadNucleos() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
}

typedef struct {
    ArbolPtr arbol;
    int nivel;
    int maxNiveles;
} ThreadData;

void* preOrderConcurrenteThread(void* ptr);
void* inOrderConcurrenteThread(void* ptr);
void* postOrderConcurrenteThread(void* ptr);

void preOrderConcurrente(ArbolPtr arbol) {
    int maxNiveles = obtenerCantidadNucleos();
    ThreadData data = {arbol, 1, maxNiveles};
    preOrderConcurrenteThread(&data);
}

void* preOrderConcurrenteThread(void* ptr) {
    ThreadData* data = (ThreadData*)ptr;
    ArbolPtr arbol = data->arbol;

    if (arbol != NULL) {
        tareaPesada(obtenerDato(arbol));
        fflush(stdout);

        pthread_t hiloIzq, hiloDer;
        ThreadData izqData = {obtenerIzq(arbol), data->nivel + 1, data->maxNiveles};
        ThreadData derData = {obtenerDer(arbol), data->nivel + 1, data->maxNiveles};

        int tieneIzq = 0, tieneDer = 0;

        if (obtenerIzq(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneIzq = 1;
                pthread_create(&hiloIzq, NULL, preOrderConcurrenteThread, &izqData);
            } else {
                preOrderConcurrenteThread(&izqData);
            }
        }

        if (obtenerDer(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneDer = 1;
                pthread_create(&hiloDer, NULL, preOrderConcurrenteThread, &derData);
            } else {
                preOrderConcurrenteThread(&derData);
            }
        }

        if (tieneIzq) pthread_join(hiloIzq, NULL);
        if (tieneDer) pthread_join(hiloDer, NULL);
    }
    return NULL;
}

void inOrderConcurrente(ArbolPtr arbol) {
    int maxNiveles = obtenerCantidadNucleos();
    ThreadData data = {arbol, 1, maxNiveles};
    inOrderConcurrenteThread(&data);
}

void* inOrderConcurrenteThread(void* ptr) {
    ThreadData* data = (ThreadData*)ptr;
    ArbolPtr arbol = data->arbol;

    if (arbol != NULL) {
        pthread_t hiloIzq, hiloDer;
        ThreadData izqData = {obtenerIzq(arbol), data->nivel + 1, data->maxNiveles};
        ThreadData derData = {obtenerDer(arbol), data->nivel + 1, data->maxNiveles};

        int tieneIzq = 0, tieneDer = 0;

        if (obtenerIzq(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneIzq = 1;
                pthread_create(&hiloIzq, NULL, inOrderConcurrenteThread, &izqData);
            } else {
                inOrderConcurrenteThread(&izqData);
            }
        }

        if (tieneIzq) pthread_join(hiloIzq, NULL);

        tareaPesada(obtenerDato(arbol));
        fflush(stdout);

        if (obtenerDer(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneDer = 1;
                pthread_create(&hiloDer, NULL, inOrderConcurrenteThread, &derData);
            } else {
                inOrderConcurrenteThread(&derData);
            }
        }

        if (tieneDer) pthread_join(hiloDer, NULL);
    }
    return NULL;
}

void postOrderConcurrente(ArbolPtr arbol) {
    int maxNiveles = obtenerCantidadNucleos();
    ThreadData data = {arbol, 1, maxNiveles};
    postOrderConcurrenteThread(&data);
}

void* postOrderConcurrenteThread(void* ptr) {
    ThreadData* data = (ThreadData*)ptr;
    ArbolPtr arbol = data->arbol;

    if (arbol != NULL) {
        pthread_t hiloIzq, hiloDer;
        ThreadData izqData = {obtenerIzq(arbol), data->nivel + 1, data->maxNiveles};
        ThreadData derData = {obtenerDer(arbol), data->nivel + 1, data->maxNiveles};

        int tieneIzq = 0, tieneDer = 0;

        if (obtenerIzq(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneIzq = 1;
                pthread_create(&hiloIzq, NULL, postOrderConcurrenteThread, &izqData);
            } else {
                postOrderConcurrenteThread(&izqData);
            }
        }

        if (obtenerDer(arbol)) {
            if (data->nivel < data->maxNiveles) {
                tieneDer = 1;
                pthread_create(&hiloDer, NULL, postOrderConcurrenteThread, &derData);
            } else {
                postOrderConcurrenteThread(&derData);
            }
        }

        if (tieneIzq) pthread_join(hiloIzq, NULL);
        if (tieneDer) pthread_join(hiloDer, NULL);

        tareaPesada(obtenerDato(arbol));
        fflush(stdout);
    }
    return NULL;
}
