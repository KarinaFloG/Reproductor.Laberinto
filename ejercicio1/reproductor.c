#include "lldblc.c"

//*------------------------------------------------------------------------------------------------------*/
Bool Reproductor_Insert(DLL* this, int num,char titulo[],char album[],char artista[],int anio,int duracion)
{
    if (DLL_Insert(this,num,titulo,album,artista,anio,duracion) == FALSE)
    {
        return FALSE;
    }
    else{
    FILE * reproductor = fopen("reproductor.txt", "a");
    
        if(reproductor ==NULL)
        {
            printf("Error al abrir el archivo\n");
        }
        else
        {
             fprintf(reproductor,"%d\n",num);
             fprintf(reproductor,"%s\n",titulo);
             fprintf(reproductor,"%s\n",album);
             fprintf(reproductor,"%s\n",artista);
             fprintf(reproductor,"%d\n",anio);
             fprintf(reproductor,"%d\n",duracion);
             //fprintf(reproductor,"%s\n",caracter);
            // fprintf(reproductor,"%d,%s,%s,%s,%d,%d\n",num,titulo,album,artista,anio,duracion);
        }
        
    fclose(reproductor);
    this -> empty = FALSE;
    }

    return TRUE;
}

//*------------------------------------------------------------------------------------------------------*/
void Reproductor_Destroy(DLL* this)
{
        DLL_Destroy (this);

}
/*--------------------------------------------------------------------------------------------------------*/
void Reproductor_Carga(DLL *this)
{
    FILE * reproductor = fopen("reproductor.txt", "r");
    char cadena[5];
    char titulo[20];
    char album[20];
    char artista[20];
    char anio[5];
    char dur[3];
    char dur2[3];
    int num,num2,num3;
    int control;
    
    
    do
    {
        if(!feof(reproductor))
        {
        fgets(cadena,5,reproductor);
        num = atoi(cadena);
  
        fgets(titulo,20,reproductor);
    
        fgets(album,20,reproductor);
   
    
        fgets(artista,20,reproductor);
   
 
        fgets(anio,5,reproductor);
        num2 = atoi(anio);
    
 
        fgets(dur,3,reproductor);
        
        fgets(dur2,3,reproductor);
        num3 = atoi(dur2);
   
 
        DLL_Insert(this,num,titulo,album,artista,num2,num3);
        control = 1;
        }
        else{
        
            control=0;
        }
   
    } while(control == 1);
    
}
/*--------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------*/
Bool Reproductor_Buscar(DLL* this, char titulo[])

//Bool Reproductor_Buscar(DLL* this, char titulo[])
{
    if (DLL_FindIf(this,titulo)==TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
   
}
/*-----------------------------------------------------------------------------------------------------*/
void Reproductor_Reproducir(DLL* this)
{
    Node* it = this -> first;
    DLL_Print(it);

}
/*------------------------------------------------------------------------------------------------*/
void Reproductor_Siguiente(DLL* this)
{
    
    DLL_Siguiente(this);
}
/*---------------------------------------------------------------------------------------------*/
void Reproductor_Anterior(DLL* this)
{
    DLL_Anterior(this);
}

/*-------------------------------------------------------------------------------------------------------
*                           Driver Program
*--------------------------------------------------------------------------------------------------------*/

int main()
{
	//Crea nueva lista enlazada 
	DLL* miLista = DLL_Create ();
    Reproductor_Carga(miLista);
    
    printf("\nCargando lista de reproduccion...\n");

	while (1)
	{
		int opcion = menu ();
		int num, anio, duracion;
        char titulo[20];
        char album[20];
        char artista[20];
        //int val;
        
        switch (opcion) {
			case 0:
				printf ("\tTerminando ...\n");
				return 0;

			case 1:
				printf ("\nIngresa el indice:\n");
				scanf("%d", &num);
				
                printf("\nTitulo de la cancion: \n");
                scanf("%s", titulo);
                
                printf("\nAlbum: \n");
                scanf("%s", album);
                
                printf("\nArtista: \n");
                scanf("%s", artista);
                
                printf("\nAnio: \n");
                scanf("%d", &anio);
                
                printf("\nDuracion: \n");
                scanf("%d", &duracion);
                
				if(Reproductor_Insert(miLista, num, titulo, album, artista, anio, duracion) == FALSE){
					printf("Error insertando\n");	
				}
				

				break;
                
    			
			case 2:
                printf("\nReproduciendo... \n");
                Reproductor_Reproducir(miLista);                   
                menu();
                    
			break;
            
			
			case 3:
				printf("\nReproduciendo siguiente cancion: \n");
                Reproductor_Siguiente(miLista);

				break;

            
            case 4:
				printf("\nReproduciendo cancion anterior: \n");
                Reproductor_Anterior(miLista);

				break;
                
			case 5:
                printf("Ingresa la cancion que deseas encontrar: \n");
                scanf("%s",titulo);
                
                Reproductor_Buscar(miLista,titulo);
        
               if(Reproductor_Buscar(miLista,titulo) == TRUE){
                    printf("\n\tLa cancion  YA se encuentra en la lista de reproduccion\n");
                }
				else {
					printf("\nLa cancion aun NO se encuentra en la lista de reproduccion\n");
				}

				
				break;	


			case 6:
				if(DLL_Empty(miLista) == TRUE){
					printf("La lista esta vacia\n");
				}
					else{
						printf("La lista contiene canciones\n");
					}

				break;							
				
			default:
				printf ("Operacion no valida!\n");
				break;
		}
	}
    
    Reproductor_Destroy(miLista);

	return 0;
}
