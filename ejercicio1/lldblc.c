#include "lldblc.h"
/*-----------------------------------------------------------------------------*/
static Node* newNode (int num, char titulo[], char album[], char artista[], int anio, int duracion)
{
	Node* n = (Node *) malloc (sizeof (Node));
    
	n -> indice = num;
    strcpy(n -> titulo, titulo);
    strcpy(n -> album, album);
    strcpy(n -> artista, artista);
    n -> anio = anio;
    n-> duracion = duracion;
	n -> next = n -> prev = NULL;

	return n;
}
/*-----------------------------------------------------------------------------*/
static void deleteNode (Node* n)
{
	if (n){	
		free (n);
	}
}

/*-----------------------------------------------------------------------------*/
DLL* DLL_Create()
{
	DLL* n = (DLL*) malloc (sizeof (DLL));

	n -> first = n -> last = NULL;
	n -> empty = TRUE;		
		
	return n;
}
/*-----------------------------------------------------------------------------*/
void DLL_Destroy (DLL* this)
{
	while (this -> first != NULL){
		Node* tmp = this -> first -> next;
		deleteNode (this -> first);
		this -> first = tmp;
	}
	free (this);
}
/*----------------------------------------------------------------------------------------------------------*/
Bool DLL_Insert (DLL* this,int num, char titulo[], char album[], char artista[], int anio, int duracion)	
{
	//Crear nuevo Nodo
	Node* n = newNode (num, titulo,album, artista, anio, duracion);
    

	//La lista esta vacia
	if (this -> empty == TRUE) 
	{ 
		this -> first = this -> last = n;
		this -> last -> next = this -> first;
		this -> first -> prev = this -> last;
		this -> empty = FALSE;
	}
	//Si la lista NO esta vacia
	else
		{
			this -> last -> next = n;
			n -> prev = this -> last;
			this -> last = n;        
			this -> last -> next = this -> first;
			this -> first -> prev = this -> last;
            this -> it = this -> first;
		}
	
	return TRUE;
	
}

/*-----------------------------------------------------------------------------*/
void DLL_Siguiente(DLL* this)
{
    //nIt es un nuevo iterador para no perder a first
    Node* nIt;
    nIt = this -> it;
    nIt = nIt -> next;   
    
    printf("\n\tIndice: %d", nIt->indice);
    printf("\n\tTitulo: %s", nIt->titulo);
    printf("\tAlbum: %s", nIt->album);
    printf("\tArtista: %s", nIt->artista);
    printf("\tAnio: %d", nIt->anio);
    printf("\n\tDuracion: %d\n", nIt->duracion);
    
    this -> it = nIt;
   // it = it -> next;
    
} 
/*-----------------------------------------------------------------------------*/
void DLL_Anterior(DLL* this)
{
    Node* nIt;
    
    nIt = this -> it;
    nIt = nIt -> prev;
    
     printf("\n\tIndice: %d", nIt->indice);
    printf("\n\tTitulo: %s", nIt->titulo);
    printf("\tAlbum: %s", nIt->album);
    printf("\tArtista: %s", nIt->artista);
    printf("\tAnio: %d", nIt->anio);
    printf("\n\tDuracion: %d\n", nIt->duracion);
    
    this -> it = nIt;
}
/*----------------------------------------------------------------------------*/
void DLL_Print(Node* it)
{
    printf("\n\tIndice: %d", it->indice);
    printf("\n\tTitulo: %s", it->titulo);
    printf("\tAlbum: %s", it->album);
    printf("\tArtista: %s", it->artista);
    printf("\tAnio: %d", it->anio);
    printf("\n\tDuracion: %d\n", it->duracion);
}
/*-----------------------------------------------------------------------------*/
Bool DLL_FindIf (DLL* this, char titulo[])
{
    Node* at = this -> it;
    
    printf("%d", at -> indice);
    
    while(this -> it != this -> last)
    {
        if (strcmp(this -> it -> titulo,titulo)==0)
        {
            printf("\nTitulo: %s", this -> it -> titulo);
            printf("\nAlbum: %s", this -> it -> album);
            
            return TRUE;
        }
        
        this -> it = this -> it -> next;
        
        if ((this -> it == this -> last) && (strcmp(this -> it -> titulo,titulo)==0))
        {
            printf("\nTitulo: %s", this -> it -> titulo);
            printf("\nAlbum: %s", this -> it -> album);
            
            return TRUE;
        }
    //at = this -> it -> next;
  
    }
    
  return FALSE;
}
/*-----------------------------------------------------------------------------*/

Bool DLL_Empty(DLL* this)
{
		//Si esta vacía devuelve TRUE
		if (this->first !=  NULL) {return FALSE;}	
		else
		{
			return TRUE;
		}
}

/*-----------------------------------------------------------------------------
*                           Menú
*-----------------------------------------------------------------------------*/

int menu()
{
	int opcion = 0;

	do {
		printf (	"\n"	
					"1 -- Insertar\n"      		
					"2 -- Reproducir\n"			
					"3 -- Siguiente\n"			 	
                    "4 -- Anterior\n"			 		
                    "5 -- Buscar\n"			
					"6 -- Esta Vacia\n"								
					"0 -- Salir\n"		
					"Su opcion> ");

		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 6);

	printf ("\n");
	return opcion;
}
/*------------------------------------------------------------------------*/
 
