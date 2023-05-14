//Diego JK
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<windows.h>
#define MAX_LENGTH 1000

typedef struct nodo
{
    char letra;
    int repeticiones;
    struct nodo *siguiente;
} Nodo;

Nodo *leer_archivo(char *ruta_archivo);
void generar_lista(Nodo *lista);
Nodo *ordenar_lista_ascendente(Nodo *lista);

Nodo *ordenar_lista_descendente(Nodo *lista);
void buscar_caracter(Nodo *lista, char caracter_buscado);

Nodo *ordenar_lista_descendente(Nodo *lista)
{
    Nodo *temp1 = lista;
    while (temp1 != NULL)
    {
        Nodo *temp2 = lista;
        while (temp2->siguiente != NULL)
        {
            if (temp2->repeticiones < temp2->siguiente->repeticiones)
            {
                int temp_rep = temp2->repeticiones;
                char temp_letra = temp2->letra;
                temp2->repeticiones = temp2->siguiente->repeticiones;
                temp2->letra = temp2->siguiente->letra;
                temp2->siguiente->repeticiones = temp_rep;
                temp2->siguiente->letra = temp_letra;
            }
            temp2 = temp2->siguiente;
        }
        temp1 = temp1->siguiente;
    }
    return lista;
}


Nodo *ordenar_lista_ascendente(Nodo *lista)
{
    Nodo *temp1 = lista;
    while (temp1 != NULL)
    {
        Nodo *temp2 = lista;
        while (temp2->siguiente->siguiente != NULL)
        {
            if (temp2->repeticiones > temp2->siguiente->repeticiones)
            {
                int temp_rep = temp2->repeticiones;
                char temp_letra = temp2->letra;
                temp2->repeticiones = temp2->siguiente->repeticiones;
                temp2->letra = temp2->siguiente->letra;
                temp2->siguiente->repeticiones = temp_rep;
                temp2->siguiente->letra = temp_letra;
                printf("[%c][%d]", temp2->letra, temp2->repeticiones);
                system("pause");
            }
            temp2 = temp2->siguiente;
        }
        temp1 = temp1->siguiente;
    }
    return lista;
}


Nodo *leer_archivo(char *ruta_archivo)
{
	int i = 0, j = 0, n, cont = 1;
	char car[MAX_LENGTH], carsinrep[MAX_LENGTH];
	
    FILE *archivo = fopen(ruta_archivo, "r");
    
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    fgets(car, MAX_LENGTH, archivo);
    fclose(archivo);
    n = strlen(car);
    
    for (i = 0; i < n; i++)car[i] = tolower(car[i]);
    
    
    for (i = 0; i < n; i++)
	{
		if (strchr(carsinrep, car[i]) == NULL) 
		{
			carsinrep[j] = car[i];//CARSINREP ES EL ARREGLO SIN CARACTERES REPETIDOS
			j++;
			cont++;
		} 
	}
    carsinrep[j] = '\0';
    int rep[cont];
    
    for (i = 0; i < cont; i++)rep[i] = 0;
    
    for (i = 0; i < cont ; i++)
    {
    	for (j = 0; j < n ; j++)
    	{
    		if(carsinrep[i] == car[j])
    		{
    			rep[i] = rep[i] + 1;//USAREMOS PARA LOS REPETIDOS
			}
		}
	}
	
	Nodo *nuevo = NULL, *lista = NULL, *aux = NULL;
	int repetido;
	char letra;
	
	i = 0;
	while(i != cont )
	{	
		if (lista == NULL)
		{
			lista = (Nodo*)malloc(sizeof(Nodo));
			repetido = rep[i];
			letra = carsinrep[i];
			lista->repeticiones = repetido;
			lista->letra = letra;
			lista->siguiente = NULL;
			aux = lista;	
		}else
		{
			nuevo = (Nodo*)malloc(sizeof(Nodo));
			repetido = rep[i];
			letra = carsinrep[i];
			nuevo->repeticiones = repetido;
			nuevo->letra = letra;
			nuevo->siguiente = NULL;
			aux->siguiente = nuevo;
			aux = aux->siguiente;
		}
		i++;
	}
	
    return lista;
}



void generar_lista(Nodo *lista)
{
	while(lista->siguiente != NULL)
	{
		printf("Letra: [%c], Repeticiones: %d\n", lista->letra, lista->repeticiones);
		lista = lista->siguiente;
	}
}




int main()
{
    int opcion;
    Nodo *lista = NULL;
    char ruta_archivo[100];
    
    do
    {
        printf("\n1. Leer archivo de texto\n");
        printf("2. Generar una lista dinamica con las letras encontradas\n");
        printf("3. Ordenar lista ascendente\n");
        printf("4. Ordenar lista descendente\n");
        printf("5. Buscar caracter\n");
        printf("6. Salir\n");
        
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
    		case 1:
    		{
			
        
            	printf("Ingrese la ruta del archivo: ");
            	scanf("%s", ruta_archivo);
	            printf("\nRuta leida con exito\n\n");
	            system("pause");
	            lista = leer_archivo(ruta_archivo);
	            fflush(stdin);
            break;
    		}
        	case 2:
        	{
			
	            if (lista == NULL)
	            {
	                printf("Primero debe leer un archivo de texto\n");
	                break;
	            }
	            generar_lista(lista);
	            printf("\nLista generada con exito\n");
            break;
        	}
	        case 3:
	        {
			
	            if (lista == NULL)
	            {
	                printf("Primero debe leer un archivo de texto\n");
	                break;
	            }
	            
	            lista = ordenar_lista_ascendente(lista);
	            printf("\nLista ordenada de manera ascendente\n");
	            system("pause");
	        break;
        	}
	        case 4:
	        {
	            if (lista == NULL)
	            {
	                printf("Primero debe leer un archivo de texto\n");
	                break;
	            }
	            
	            ordenar_lista_descendente(lista);
	            printf("Lista ordenada de manera descendente\n");
	            system("pause");
	        break;
        	}
	        case 5:
	        {
	            if (lista == NULL)
	            {
	                printf("Primero debe leer un archivo de texto\n");
	                break;
	            }
	            /*
	            char caracter_buscado;
	            printf("Ingrese el caracter a buscar: ");
	            scanf(" %c", &caracter_buscado);
	            buscar_caracter(lista, tolower(caracter_buscado)); */
	        break;
        	}
	        case 6:
	        {
	            printf("Saliendo...\n");
	            exit(0);
	    	}
	        default:
	        {
	        	system("cls");
	            printf("\nOpcion invalida\n");
	            fflush(stdin);
	            system("pause");
	        break;
	    	}
        }
    }while (1);

    return 0;
}
