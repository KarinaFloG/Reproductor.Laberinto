#include "ll.c"

void Cajero_Limpiar(Cajero *this)
{
	while(this->first != NULL){
		Nodo *tmp = this->first->next;
		Cajero_DeleteNode (this->first);
		this->first = tmp;
	}
	
	this->last = NULL;
}
/*-------------------------------------------------------------------------------------*/
Bool Cajero_Debitar(Cajero *this,Cajero *other,int debito,int efectivo){
	Nodo *it = this->first;
	int tmp = efectivo;
	
	while(it != NULL){
		if (debito > 0){
			if (it->cantidad > 0){
				if(debito - it->denominacion >= 0){
					Cajero_Insertar (other,it->denominacion,1);
					debito = debito - it->denominacion;
					it->cantidad -= 1;
					efectivo = efectivo - it->denominacion;
				}
				else{
					it = it->next;
				}
			}
			else{
				it = it->next;
			}
		}
		else{
			it = NULL;
		}
	}
	
	if(debito != 0)
    {
		it = this->first;
		while (it != NULL){
			if (debito + it->denominacion > tmp){
				it = it->next;
			}
			else{
				debito = debito + it->denominacion;
				it->cantidad += 1;
				efectivo += it->denominacion;
			}
		}
		Cajero_Limpiar(other);
	    return FALSE; 
	}
	else{
		return TRUE;
	}
}
/*------------------------------------------------------------------------------------------*/
void Cajero_PrintSolucion(Cajero *this){
	Nodo *it = this->first;
	
	printf ("**");
	
	while (it != NULL){
		printf (" %i ",it->denominacion);
	    it = it->next;
	} 
	
	printf ("**\n\n");
}

/*----------------------------------------------------------------------------------------------*/
int main()
{
	int denominaciones[TAM]={500,200,100,50,20};
	int efectivo = 0;
    int debito;
	int res,i;
	
	Cajero *miLista = Cajero_Create();
	
	for (i=0; i<TAM; i++){
		printf ("El efectivo actual es: %i\n",efectivo);
		printf ("Ingrese la cantidad de billetes de %i: ",denominaciones[i]);
		scanf ("%i",&debito);
		int res = Cajero_Insertar(miLista,denominaciones[i],debito);
		if (res == TRUE){
		    efectivo = efectivo + denominaciones[i]*debito;
		    printf ("\n\tSe ingreso correctamente\n\n");
		}	
	}
	

	while(1){
		
		Cajero *Cola = Cajero_Create();
		int opcion = Principal();
		
		switch(opcion){
	  	    case 1:
                
	   		    printf ("\n\tTERMINANDO ... \n");
	   		    Cajero_Destruir (miLista);
	   		    Cajero_Destruir (Cola);
	   		    break;
	   		    
	   		case 2:
	   		    if (efectivo > 0){
	   		    	printf ("ingrese la cantidad: ");
	   		    	scanf ("%i",&debito);
	   		    	
	   				if (efectivo-debito >= 0){
	   					res = Cajero_Debitar(miLista,Cola,debito,efectivo);
	   					if (res == TRUE){
	   						efectivo = efectivo-debito;
	   						Cajero_PrintSolucion(Cola);
	   						Cajero_Limpiar(Cola);
	   					}
	   					else{
	   						printf ("\n\tEl cambio no se puede dar exacto\n");
	   					}
	   				}
	   				else{
	   					printf ("No se puede dar %i en cambio.\n",debito);
	   				}
	   			}
	   			else{
	   				printf ("\n\tSe ha agotado el cambio.");
	   			}
	   			break;
	   		
	        case 3:
	    	    printf ("Efectivo actual: %i.\n\n",efectivo);
	    	    break;
	    }
	}
return 0;
}
