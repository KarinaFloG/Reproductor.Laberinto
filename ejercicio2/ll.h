#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 7
/*--------------------------------------------------------------------------------*/
typedef enum { FALSE = 0, TRUE = !FALSE } Bool;
//Permite devolver TRUE y FALSE en funciones Bool//
/*---------------------------------------------------------------------------------*/
struct Nodo_Type{
	int denominacion;
	int cantidad;
	struct Nodo_Type *next;
};typedef struct Nodo_Type Nodo;
/*---------------------------------------------------------------------------------*/

struct Cajero_Type{
	Nodo *first;
	Nodo *last;
	Bool empty;
};typedef struct Cajero_Type Cajero;
/*----------------------------------------------------------------------------------*/
//void Cajero_Limpiar(Cajero *this){
    /*Recibe un apuntador a una lista enlazada simple
     *Hace uso de la funcion Cajero_DeleteNode que pertenece a la lista y va borrarndo
     * los nodos
     * No devuelve nada */
/*----------------------------------------------------------------------------------*/
//Bool Cajero_Debitar(Cajero *this,Cajero *other,int debito,int efectivo){
    /*Recibe un apuntador a una lista enlazada simple
     * Recibe un apuntador a una cola con una lista enlazada subyacente
     * Recibe la cantidad a debitar y la cantidad de efectivo
     * Si debita correctamente regresa TRUE */
/*----------------------------------------------------------------------------------*/
//void Cajero_PrintSolucion (Cajero *this){
    /*Recibe como parametros un apuntador a la lista enlazada
     * Imprime el conjunto */
/*---------------------------------------------------------------------------------------*/
