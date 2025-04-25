#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct NodoE {
    int dato;
    struct NodoE * siguiente;
};

// CONSTRUCTORES
NodoPtr crearNodo(int dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct NodoE));

    if (nodo == NULL) {
        printf("\nERROR: No se pudo asignar memoria para el nodo.");
        exit(-1);
    }

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

// GET Y SET
int getNodoDato(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("\nERROR: El nodo es NULL.");
        return -1;
    }
    return nodo->dato;
}

NodoPtr getNodoSiguiente(NodoPtr nodo) {
    if (nodo == NULL) {
        printf("\nERROR: El nodo es NULL.");
        return NULL;
    }

    return nodo->siguiente;
}

void setNodoDato(NodoPtr nodo, int nuevoDato) {
    if (nodo == NULL) {
        printf("\nERROR: Intentando modificar el dato de un nodo NULL.");
        return;
    }
    nodo->dato = nuevoDato;
}

void setNodoSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente) {
    if (nodo == NULL) {
        printf("\nERROR: Intentando modificar el siguiente de un nodo NULL.");
        return;
    }
    nodo->siguiente = nuevoSiguiente;
}

// MOSTRAR
void mostrarNodo(NodoPtr nodo){
    if (nodo == NULL) {
        printf("[NULL]");
        return;
    }

    printf("{ %d }", getNodoDato(nodo));
};

// DESTRUCTOR
void liberarNodo(NodoPtr nodo){
    free(nodo);
};
