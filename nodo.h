#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct NodoE;

typedef struct NodoE * NodoPtr;

// CONSTRUCTORES
NodoPtr crearNodo(int dato, NodoPtr siguiente);

// GET Y SET
int getNodoDato(NodoPtr nodo);
NodoPtr getNodoSiguiente(NodoPtr nodo);

void setNodoDato(NodoPtr nodo, int nuevoDato);
void setNodoSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

// MOSTRAR
void mostrarNodo(NodoPtr nodo);

// DESTRUCTOR
void liberarNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
