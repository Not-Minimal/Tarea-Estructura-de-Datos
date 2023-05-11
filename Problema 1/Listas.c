//Diego JK
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 9999 // Tamano maximo del arreglo de caracteres

typedef struct nodo
{
	char letra; 
	int rep;
	struct nodo *sig
}*NODO;

int menu();
void mostrar_lista(NODO lista);
NODO crear_lista(NODO lista);//Crea lista

int main()
{
	int op, p, flag = 0;
	NODO lista = NULL;
	
	FILE *text;
	text = fopen("texto.txt", "r");
	p = fgetc(text);
	fclose(text);
	
	do
	{
		op = menu();
		
		switch(op)
		{
			case 1://CREAR LA LISTA CON LOS DATOS
				if(p != EOF)
				{
                    printf("\nTEXTO LEIDO CORRECTAMENTE\n");
                    flag = 1;
					system("pause");					
				}else
				{
                    flag = 0;
					printf("\nNO HAY TEXTO PARA TRABAJAR\n");
					system("pause");
				}			
				break;
			case 2:
				if(flag == 1)
				{
                    lista = crear_lista(lista);
					mostrar_lista(lista);
				}else
				{
					printf("\nNO HAY TEXTO PARA TRABAJAR\n");
					system("pause");
				}
				break;
			case 3:
				if(flag == 0)
				{
				}else
				{
					printf("\nNO HAY TEXTO PARA TRABAJAR\n");
					system("pause");
				}
				break;
			case 4:
				if(p != EOF)
				{
				}else
				{
					printf("\nNO HAY TEXTO PARA TRABAJAR\n");
					system("pause");
				}		
				break;
			case 5:
				if(flag == 0)
				{
				}else
				{
					printf("\nNO HAY TEXTO PARA TRABAJAR\n");
					system("pause");
				}
				break;
			default://SALIR CON -1
				
				return 0;
				break;
		}
		system("cls");
	}while(1);
    return 0;
}

int menu()
{
	int op = 1;
	do
	{
		if(op<1 || op>5)
		{
			printf("Error, Ingrese opcion valida\n");
			system("pause");
			system("cls");
		}
		printf("     Seleccione opcion:\n");
		printf(" <1> Leer caracteres de entrada mediante archivo .txt\n");
		printf(" <2> Crear lista con la cantidad de apariciones de cada caracter.\n");
		printf(" <3> Ordenar lista de forma ascendente.\n");
		printf(" <4> Ordenar lista de forma descendente.\n");
		printf(" <5> Buscar caracter en especifico y su numero de apariciones.\n");
		scanf("%d", &op);
		fflush(stdin);
		if(op>0 && op<6)return op;
		if(op == -1)return op;
	}while(1);
}

NODO crear_lista(NODO lista)
{
	NODO nuevo, aux;
	int i = 0, j = 0, n, cont = 0;
	char car[MAX_LENGTH], carsinrep[MAX_LENGTH];
	
	FILE *texto;
	texto = fopen("texto.txt", "r");
    if (texto == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }	
	fgets(car, MAX_LENGTH, texto);
	fclose(texto);
	
	n = strlen(car);
    for (i = 0; i < n; i++)
	{
		if (strchr(carsinrep, car[i]) == NULL) 
		{
			carsinrep[j++] = car[i];
			cont++;
		} 
	} 
    carsinrep[j] = '\0'; //Deja un enter en la ultima posicion como limite del arreglo
    int rep[cont + 1];
    for (i = 0; i < cont + 1; i++)rep[i] = 0;//LLENO DE 0 EL ARREGLO
    for (i = 0; i < cont + 1; i++)
    {
    	for (j = 0; j < n + 1; i++)
    	{
			if(carsinrep[i] == car[j])
    		{
    			rep[i]++;
			}
		}
	}
    
    for (i = 0; carsinrep[i] != '\0'; i++)
    {
    	nuevo = malloc(sizeof(NODO));
        nuevo->letra = carsinrep[i];
        nuevo->rep = rep[i];
        nuevo->sig = NULL;
        if (lista == NULL)
        {
            lista = nuevo;
            aux = nuevo;	        
        } else 
        {
            aux->sig = nuevo;
            aux = nuevo;
        }
	}
	
	return lista;
}

void mostrar_lista(NODO lista)
{
	int i=0;
	printf("\n");
	printf("    |Datos|posicion|\n");
    while(lista->sig != NULL)
    {
        printf("    [ %c/%d ]   (%d)", lista->letra, lista->rep, i+1);
        lista = lista->sig;
        printf("\n");
        i++;
    }
    
}
