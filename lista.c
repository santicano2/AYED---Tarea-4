#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct ListaE{
    NodoPtr primero;
};

// CONSTRUCTORES
ListaPtr crearLista(){
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct ListaE));

    if (lista == NULL) {
        printf("\ERROR: No se pudo asignar memoria para la lista.");
        exit(-1);
    }

    lista->primero = NULL;

    return lista;
};

// GET Y SET
NodoPtr getPrimero(ListaPtr lista) {
    if (lista == NULL) {
        printf("\ERROR: Intentando acceder al primer nodo de una lista NULL.");
        return NULL;
    }
    return lista->primero;
}

void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero) {
    if (lista == NULL) {
        printf("\ERROR: Intentando modificar el primer nodo de una lista NULL.");
        return;
    }
    lista->primero = nuevoPrimero;
}

// MOSTRAR
void mostrarLista(ListaPtr lista){
    if (lista == NULL) {
        printf("\n<LISTA NULA>\n");
        return;
    }

    printf("\n<LISTA>\n");
    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL){
        mostrarNodo(actual);
        actual = getNodoSiguiente(actual);
    }

    printf("\n\n");
};

// DESTRUCTOR
void liberarLista(ListaPtr lista) {
    if (lista == NULL) return;

    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL){
        NodoPtr aux = actual;

        actual = getNodoSiguiente(actual);
        liberarNodo(aux);
    };

    free(lista);
}

// OPERACIONES
void insertarPrimero(ListaPtr lista, int dato){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    NodoPtr nuevoNodo = crearNodo(dato, getPrimero(lista));

    setPrimero(lista, nuevoNodo);

};

void insertarUltimo(ListaPtr lista, int dato){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    NodoPtr actual = getPrimero(lista);

    if (actual == NULL){ /// Lista no tiene nodos
        insertarPrimero(lista, dato);
        return;
    }

    /// Recorrer hasta ultimo nodo
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, NULL));

};

void insertarPosicion(ListaPtr lista, int dato, int posicion){
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return;
    }

    int tam = obtenerTamanio(lista);

    if (posicion < 0) {
        printf("\nERROR: No se puede insertar en posiciones negativas");
        return;
    }

    if (posicion > tam) {
        printf("\nERROR: No se puede insertar en una posicion que no existe");
        return;
    }

    if (posicion == 0) {
        insertarPrimero(lista, dato);
        return;
    }

    if (posicion == tam) {
        insertarUltimo(lista, dato);
        return;
    }

    /// INSERTAR
    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < posicion - 1; i++) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, getNodoSiguiente(actual)));

};

int obtenerPrimero(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return -1;
    }

    return getNodoDato(getPrimero(lista));
};

int obtenerUltimo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return -1;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    return getNodoDato(actual);
};

int obtenerPosicion(ListaPtr lista, int pos) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return -1;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return -1;
    }

    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos; i++) {
        actual = getNodoSiguiente(actual);
    }

    return getNodoDato(actual);
};


int eliminarPrimero(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return -1;
    }

    NodoPtr nodoEliminar = getPrimero(lista);
    int valorRetorno = getNodoDato(nodoEliminar);

    setPrimero(lista, getNodoSiguiente(nodoEliminar));
    liberarNodo(nodoEliminar);

    return valorRetorno;
};

int eliminarUltimo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        printf("\nERROR: La lista esta vacia o es NULL");
        return -1;
    }

    if (getNodoSiguiente(getPrimero(lista)) == NULL) {
        /// Solo un nodo
        int valorRetorno = getNodoDato(getPrimero(lista));
        liberarNodo(getPrimero(lista));
        setPrimero(lista, NULL);
        return valorRetorno;
    }

    /// Mas de un nodo
    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(getNodoSiguiente(actual)) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    int valorRetorno = getNodoDato(getNodoSiguiente(actual));
    liberarNodo(getNodoSiguiente(actual));
    setNodoSiguiente(actual, NULL);

    return valorRetorno;
};

int eliminarPosicion(ListaPtr lista, int pos) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return -1;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return -1;
    }

    if (pos == 0) {
        return eliminarPrimero(lista);
    }

    if (pos == tam - 1) {
        return eliminarUltimo(lista);
    }

    /// ELIMINAR
    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos - 1; i++) {
        actual = getNodoSiguiente(actual);
    }

    NodoPtr nodoEliminar = getNodoSiguiente(actual);
    int valorRetorno = getNodoDato(nodoEliminar);

    setNodoSiguiente(actual, getNodoSiguiente(nodoEliminar));
    liberarNodo(nodoEliminar);

    return valorRetorno;
};

NodoPtr obtenerPrimeroNodo(ListaPtr lista) {
    if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    return getPrimero(lista);
};

NodoPtr obtenerUltimoNodo(ListaPtr lista) {
    if (lista == NULL || getPrimero(lista) == NULL) {
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL) {
        actual = getNodoSiguiente(actual);
    }

    return actual;
};

NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos) {
   if (lista == NULL) {
        printf("\nERROR: Lista es NULL");
        return NULL;
    }

    int tam = obtenerTamanio(lista);

    if (pos < 0 || pos >= tam) {
        printf("\nERROR: Posicion fuera de rango");
        return NULL;
    }

    NodoPtr actual = getPrimero(lista);
    for (int i = 0; i < pos; i++) {
        actual = getNodoSiguiente(actual);
    }

    return actual;
};

int obtenerTamanio(ListaPtr lista){
    if (lista == NULL) return 0;

    int i = 0;

    NodoPtr actual = getPrimero(lista);

    while (actual!=NULL) {
        i++;
        actual = getNodoSiguiente(actual);
    }

    return i;

};

// ORDERNAR
void ordenarLista(ListaPtr lista){ /// Burbuja
    if (lista == NULL) return;

    int n = obtenerTamanio(lista);
    if (n <= 1) return;  // NO SE ORDENA

    int intercambio;
    for (int i = 0; i < n; i++) {
        intercambio = 0;
        NodoPtr actual = getPrimero(lista);

        for (int j = 0; j < n - i - 1; j++) {
            if (getNodoDato(actual) > getNodoDato(getNodoSiguiente(actual))) {
                // INTERCAMBIAR
                int temp = getNodoDato(actual);
                setNodoDato(actual, getNodoDato(getNodoSiguiente(actual)));
                setNodoDato(getNodoSiguiente(actual), temp);
                intercambio = 1;
            }
            actual = getNodoSiguiente(actual);
        }

        /// Ya ordenado
        if (intercambio == 0) break;
    }
};

ListaPtr ordenarListaCopia(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = duplicarLista(lista);
    ordenarLista(nuevaLista);
    return nuevaLista;
};

ListaPtr duplicarLista(ListaPtr lista) {
    if (lista == NULL) return NULL;

    ListaPtr nuevaLista = crearLista();

    NodoPtr actual = getPrimero(lista);
    while (actual != NULL) {
        insertarUltimo(nuevaLista, getNodoDato(actual));
        actual = getNodoSiguiente(actual);
    }

    return nuevaLista;
};

// BUSQUEDA
int buscarElemento(ListaPtr lista, int datoBuscado) {
    if (lista == NULL) return -1;

    NodoPtr actual = getPrimero(lista);
    int posicion = 0;

    while (actual != NULL) {
        if (getNodoDato(actual) == datoBuscado) {
            return posicion;
        }
        actual = getNodoSiguiente(actual);
        posicion++;
    }

    return -1;  /// NO SE ENCONTRO
};

void insertarEnOrden(ListaPtr lista, int dato) {
    if (lista == NULL) return;

    if (getPrimero(lista) == NULL || getNodoDato(getPrimero(lista)) >= dato) {
        insertarPrimero(lista, dato);
        return;
    }

    NodoPtr actual = getPrimero(lista);
    while (getNodoSiguiente(actual) != NULL && getNodoDato(getNodoSiguiente(actual)) < dato) {
        actual = getNodoSiguiente(actual);
    }

    setNodoSiguiente(actual, crearNodo(dato, getNodoSiguiente(actual)));
};
