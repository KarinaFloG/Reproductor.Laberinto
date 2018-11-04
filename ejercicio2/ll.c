#include "ll.h"

static Nodo* newNode(int val,int can)
{
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->denominacion = val;
	n->cantidad = can;
	n->next = NULL;
	
	return n;
}
/*------------------------------------------------------------------------*/
Bool Cajero_Insertar(Cajero *this,int valor,int res){
	Nodo *n = newNode(valor,res);
	
	if(this->empty == TRUE){
		this->first = this->last = n;
		this->empty = FALSE;
	}
	else{
		this->last->next = n;
		this->last = n;
	}
	return TRUE;
}
/*------------------------------------------------------------------------*/
void Cajero_DeleteNode (Nodo *n){
	if (n){
		free (n);
	}
}
/*------------------------------------------------------------------------*/
Cajero* Cajero_Create(){
	Cajero *n = (Cajero*)malloc(sizeof(Cajero));
	n->first = n->last = NULL;
	n->empty = TRUE;
	
	return n;
}
/*------------------------------------------------------------------------*/
void Cajero_Destruir (Cajero *this){
	
	while (this->first != NULL){
		Nodo *tmp = this->first->next;
		Cajero_DeleteNode (this->first);
		this->first = tmp;
	}
	
	free (this);
}

/*------------------------------------------------------------------------*/
int Principal (){
	int opcion = 0;
	
	do{	
	    printf ("\n1...Salir.\n"
			    "2...Debitar.\n"
			    "3... Ver efectivo remanente.\n"
			    "\nSu opcion: ");
	    scanf ("%d",&opcion);
	    
    }while (opcion < 0 || opcion > 3);
    
    return opcion;
}
