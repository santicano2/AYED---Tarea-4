#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    printf("\nTAM INICIAL: %d", obtenerTamanio(lista));
    mostrarLista(lista);

    printf("\n\n== INSERTANDO NODOS ==");
    insertarUltimo(lista, 34);
    insertarPrimero(lista, 4);
    insertarPrimero(lista, 1);
    insertarUltimo(lista, 11);
    insertarPrimero(lista, -26);
    insertarUltimo(lista, 64);
    insertarPrimero(lista, 96);

    ///96 -26 1 4 34 11 64
    printf("\nTAM DESPUES DE INSERTAR: %d", obtenerTamanio(lista));
    mostrarLista(lista);


    printf("\n\n== INSERTANDO NODOS EN POSICIONES ==");
    ///85 96 -26 44 1 4 34 11 64 101
    insertarPosicion(lista, 44, 2);
    insertarPosicion(lista, 85, 0);
    insertarPosicion(lista, 101, 9);
    insertarPosicion(lista, 85, -1);
    insertarPosicion(lista, 85, 12);

    printf("\n\n== LISTA DESPUES DE INSERTAR POSICIONES ==");
    mostrarLista(lista);

    printf("\nPRIMER ELEMENTO: %d", obtenerPrimero(lista));
    printf("\nULTIMO ELEMENTO: %d", obtenerUltimo(lista));
    printf("\nELEMENTO EN POSICION 3: %d\n", obtenerPosicion(lista, 3));

    printf("\nELIMINAR PRIMERO %d", eliminarPrimero(lista));
    printf("\nELIMINAR ULTIMO: %d", eliminarUltimo(lista));
    printf("\nELIMINAR POSICION 2: %d", eliminarPosicion(lista, 2));

    ///96 -26 1 4 34 11 64
    printf("\n\n== LISTA DESPUES DE ELIMINAR NODOS ==");
    mostrarLista(lista);

    printf("\nBUSCANDO ELEMENTO 4, POSICION: %d", buscarElemento(lista, 4));
    /// -1: NO SE ENCONTRO
    printf("\nBUSCANDO ELEMENTO 99, POSICION: %d", buscarElemento(lista, 99));

    ///96 -26 1 4 34 11 64
    printf("\n\nLISTA ORIGINAL:");
    mostrarLista(lista);

    ///-26 1 4 11 34 64 96
    printf("\nORDENANDO LISTA...");
    ordenarLista(lista);
    mostrarLista(lista);

    ///-26 1 4 11 34 50 64 96
    printf("\nINSERTAR EN ORDEN EL VALOR 50");
    insertarEnOrden(lista, 50);
    mostrarLista(lista);

    printf("\nCREAR COPIA DE LA LISTA");
    ListaPtr listaCopia = duplicarLista(lista);
    mostrarLista(listaCopia);

    printf("\nLIBERANDO MEMORIA...");
    liberarLista(lista);
    liberarLista(listaCopia);
    printf("\n\nMEMORIA LIBERADA.");


    return 0;
}
