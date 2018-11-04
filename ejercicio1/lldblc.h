/*-----------------------------------------------------------------------------
 *                           Lista Doblemente Enlazada Circular
 *-----------------------------------------------------------------------------*/
#include<stdlib.h>
#include <string.h>
#include<stdio.h>
/*-----------------------------------------------------------------------------*/
enum {FALSE = 0, TRUE = !FALSE};
typedef unsigned int Bool;
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
struct Node_Type 
{
	int indice;
    char titulo[20];
    char album[20];
    char artista[20];
    int anio;
    int duracion;
	struct Node_Type* next;
	struct Node_Type* prev;
};
typedef struct Node_Type Node;
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
struct DLL_Type 
{
	Node* first;
	Node* last;
    Node* it;
    //It es un nuevo apuntador que se encargara de recorre la lista sin perder los demas apuntadores
    //de su lugar
	Bool empty;
};
typedef struct DLL_Type DLL;
/*------------------------------------------------------------------------------------------------------------*/
Bool Reproductor_Insert(DLL* this, int num,char titulo[],char album[],char artista[],int anio,int duracion);
/*Recibe como parametros el indice, titulo,album,artista,anio,duracion
     *Ocupa a la funcion DLL_Insert de la lista Ldec para insertar en un nodo de dicha lista que se crea dinamicamente
     *Regresa TRUE si el nodo y los datos fueron insertados con exito y FALSE de lo contrario
     *Abre un archivo.txt que ya fue creado anteriormente y ya contiene canciones 
     * inserta los datos nuevos en la lista y en el archivo
     * El archivo es llamado reproductor.txt
     * Cuando sale cierra el archivo y cambia la bandera de empty a FALSE */
/*------------------------------------------------------------------------------------------------------------*/
void Reproductor_Destroy(DLL* this);
/*Recibe como parametro un apuntador a una lista que ya existe
     * La lista es con la que se ha trabajado
     * Ocupada la funcion DLL_Destroy para eliminar los datos de la lista y devolver memoria
     * Los datos se mantienen en el archivo 
     */
/*------------------------------------------------------------------------------------------------------------*/
void Reproductor_Carga(DLL *this);
/*Carga los datos existentes en el archivo a la lista
     * Va ingresando los datos de cada cancion nodo por nodo
     * Va creando los nodos con ayuda de DLL_Insert la cual se encarga de ir creando la lista de nuevo
     * Se carga cada que el usuario inicializa la aplicacion */
/*------------------------------------------------------------------------------------------------------------*/
Bool Reproductor_Buscar(DLL* this, char titulo[]);
  /*Recibe como parametros un apuntador a la lista con la que se esta trabajando y la cancion a Reproductor_Buscar
     *Con ayuda de DLL_FindIf busca en la lista el nombre de la cancion 
     * Devuelve TRUE si ya existe una cancion con ese nombre
     * Devuelve FALSE si no hay cacniones con ese nombre
     * Compara el titulo contra el campo titutlo de cada nodo*/
/*------------------------------------------------------------------------------------------------------------*/
void Reproductor_Reproducir(DLL* this);
    /*Recibe como parametro un apuntador a lista con la que se esta trabajando
     * Con ayuda de  la funcion DLL_Reproducir que pertenece a la lista muestra la informacion de la primera cancion
     *Con ayuda de DLL_Reproducir imprime los datos de cada cancion cuando se elige la opcion "reproducir"
     * No devuelve nada*/
/*------------------------------------------------------------------------------------------------------------*/
void Reproductor_Siguiente(DLL* this);
    /*Recibe como parametro un apuntador a lista con la que se esta trabajando
     * Con ayuda de  la funcion DLL_Reproducir que pertenece a la lista recorre los nodos 
     *Recorre la lista con el apuntador next
     *Con ayuda de DLL_Siguiente imprime los datos de cada cancion cuando se elige la opcion "siguiente"
     * No devuelve nada*/
/*------------------------------------------------------------------------------------------------------------*/
void Reproductor_Anterior(DLL* this);
/*Recibe como parametro un apuntador a lista con la que se esta trabajando
     * Con ayuda de  la funcion DLL_Anterior que pertenece a la lista recorre los nodos 
     *Recorre la lista con el apuntador prev
     *Con ayuda de DLL_Anterior imprime los datos de cada cancion cuando se elige la opcion "siguiente"
     * No devuelve nada*/
