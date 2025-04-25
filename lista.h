#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct ListaE;

typedef struct ListaE * ListaPtr;

// CONSTRUCTORES
ListaPtr crearLista();

// GET Y SET
NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

// MOSTRAR
void mostrarLista(ListaPtr lista);

// DESTRUCTOR
void liberarLista(ListaPtr lista);

// OPERACIONES
void insertarPrimero(ListaPtr lista, int dato);///
void insertarUltimo(ListaPtr lista, int dato); //tarea <----
void insertarPosicion(ListaPtr lista, int dato, int posicion); //tarea x

int obtenerPrimero(ListaPtr lista); //tarea <----
int obtenerUltimo(ListaPtr lista); //tarea <----
int obtenerPosicion(ListaPtr lista,int pos); //tarea

int eliminarPrimero(ListaPtr lista); //tarea <----
int eliminarUltimo(ListaPtr lista); //tarea <----
int eliminarPosicion(ListaPtr lista, int pos); //tarea

NodoPtr obtenerPrimeroNodo(ListaPtr lista);
NodoPtr obtenerUltimoNodo(ListaPtr lista); //tarea
NodoPtr obtenerPosicionNodo(ListaPtr lista,int pos); //tarea

int obtenerTamanio(ListaPtr lista); ///tarea <----

// ORDERNAR
void ordenarLista(ListaPtr lista);///tarea <---- x
ListaPtr ordenarListaCopia(ListaPtr lista);//tarea

ListaPtr duplicarLista(ListaPtr lista);//tarea

// BUSQUEDA
int buscarElemento(ListaPtr lista, int datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, int dato);//tarea, si la lista est� ordenada cada vez que
//se inserta se inserta en la posici�n que corresponda

#endif // LISTA_H_INCLUDED
