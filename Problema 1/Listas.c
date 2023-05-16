#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo
{
    char letra;
    int repeticiones;
    struct nodo *siguiente;
} Nodo;

Nodo *leer_archivo(char *ruta_archivo);
void mostrar_lista(Nodo *lista);
void buscar_caracter(Nodo *lista, char caracter_buscado);
void liberar_lista(Nodo *lista);

Nodo *leer_archivo(char *ruta_archivo)
{
    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    Nodo *inicio = NULL;
    Nodo *nodo_actual = NULL;
    char caracter;
    while ((caracter = fgetc(archivo)) != EOF)//lee cada caracter del archivo
    {
        char letra = tolower(caracter);//copia letra en minuscula
        Nodo *nodo_actual_letra = inicio;//comienza en el primer nodo
        while (nodo_actual_letra != NULL)//recorre la lista dando nuevos nodos
        {
            if (nodo_actual_letra->letra == letra)
            {
                nodo_actual_letra->repeticiones++;//aumenta la repeticion
                break;
            }
            if (nodo_actual_letra->siguiente == NULL)//si el que sigue es nulo se crea otro nodo
            {
                Nodo *nuevo_nodo = malloc(sizeof(Nodo));
                nuevo_nodo->letra = letra;
                nuevo_nodo->repeticiones = 1;
                nuevo_nodo->siguiente = NULL;
                nodo_actual_letra->siguiente = nuevo_nodo;
                break;
            }
            nodo_actual_letra = nodo_actual_letra->siguiente;
        }
        if (nodo_actual_letra == NULL)//si la lista esta vacia
        {
            Nodo *nuevo_nodo = malloc(sizeof(Nodo));
            nuevo_nodo->letra = letra;
            nuevo_nodo->repeticiones = 1;
            nuevo_nodo->siguiente = NULL;
            if (inicio == NULL)//inicia la lista
            {
                inicio = nuevo_nodo;
            }
            else//sigue dandole valores a la lista
            {
                nodo_actual->siguiente = nuevo_nodo;
            }
            nodo_actual = nuevo_nodo;
        }
    }
    fclose(archivo);
    return inicio;
}

void mostrar_lista(Nodo *lista)
{
    while (lista != NULL)
    {
        printf("Letra: [%c], Repeticiones: %d\n", lista->letra, lista->repeticiones);
        lista = lista->siguiente;
    }
}

void buscar_caracter(Nodo *lista, char caracter_buscado)
{
    int encontrado = 0;
    while (lista != NULL)
    {
        if (lista->letra == caracter_buscado)
        {
            printf("\nCaracter encontrado:\n");
            printf("Caracter: [%c], Frecuencia: %d\n", caracter_buscado, lista->repeticiones);
            encontrado = 1;
            break;
        }
        lista = lista->siguiente;
    }
    if (!encontrado)
    {
        printf("\nCaracter NO encontrado \n");
    }
}

void liberar_lista(Nodo *lista)
{
    Nodo *nodo_actual = lista;
    while (nodo_actual != NULL)
    {
        Nodo *siguiente_nodo = nodo_actual->siguiente;
        free(nodo_actual);
        nodo_actual = siguiente_nodo;
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
        printf("3. Buscar caracter\n");
        printf("4. Salir\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");

        switch (opcion)
        {
            case 1:
            {
                printf("Ingrese la ruta del archivo");
                printf(": ");
                scanf("%s", ruta_archivo);
                lista = leer_archivo(ruta_archivo);
                printf("\nArchivo de texto leido con exito.\n");
                break;
            }
            case 2:
            {
                if (lista == NULL)
                {
                    printf("\nPrimero debe leer un archivo de texto.\n");
                }
                else
                {
                    printf("\nLista generada:\n");
                    mostrar_lista(lista);
                }
                break;
            }
            case 3:
            {
                if (lista == NULL)
                {
                    printf("\nPrimero debe leer un archivo de texto.\n");
                }
                else
                {
                    char caracter_buscado;
                    printf("\nIngrese el caracter a buscar: ");
                    scanf(" %c", &caracter_buscado);
                    buscar_caracter(lista, caracter_buscado);
                }
                break;
            }
            case 4:
            {
                liberar_lista(lista);
                printf("\nSaliendo del programa...\n");
                break;
            }
            default:
            {
                printf("\nOpcion invalida. Intente de nuevo.\n");
                break;
            }
        }

    } while (opcion != 4);

    return 0;
}
