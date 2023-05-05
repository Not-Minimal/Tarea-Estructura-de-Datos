// Primero Creare una Fila Circular Comun y corriente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10 // Tamaño maximo de la fila
int tiempoEspera = 0, retiro = 5, Deposito = 2, Consulta = 4, Actualizacion = 5, Pagos = 6;

// Estructura de la fila
typedef struct
{
    int front, rear;
    char *nombre[MAX];
    int transaccion[MAX];
    int tiempoEspera;
} FilaCircular;

// Prototipo de Funciones
void inicializarFilaCircular(FilaCircular *link);
int filaVacia(FilaCircular *link);
int filaLlena(FilaCircular *link);
void agregarCliente(FilaCircular *link, char *nombre, int transaccion);
int eliminarCliente(FilaCircular *link);
void imprimirFilaCircular(FilaCircular *link);
int calcularEspera(FilaCircular *link);

// Iniciar la Fila por Defecto
void inicializarFilaCircular(FilaCircular *link)
{
    link->front = link->rear = -1;
}

// Verificar si la Fila esta vacia
int filaVacia(FilaCircular *link)
{
    return (link->front == -1);
}

// Verificar si la fila esta llena
int filaLlena(FilaCircular *link)
{
    return ((link->rear + 1) % MAX == link->front);
}

// Agregar un nuevo Clientes a la fila›
void agregarCliente(FilaCircular *link, char *nombre, int transaccion)
{

    if (filaLlena(link))
    {
        return;
    }
    else
    {
        link->rear = (link->rear + 1) % MAX;
        link->nombre[link->rear] = (char *)malloc(strlen(nombre) + 1);
        strcpy(link->nombre[link->rear], nombre);
        link->transaccion[link->rear] = transaccion;
        link->tiempoEspera = link->tiempoEspera + transaccion;
        if (link->front == -1)
        {
            link->front = link->rear;
        }
    }
}

// Eliminar Clientes de la Lista
int eliminarCliente(FilaCircular *link)
{

    if (filaVacia(link))
    {
        return 0;
    }
    else
    {
        char *nombre = link->nombre[link->front];
        int transaccion = link->transaccion[link->front];
        printf("Se ha eliminado a %s y el tiempo de espera ha bajado en %d minutos. \n", nombre, transaccion);
        free(nombre);
        if (link->front == link->rear)
        {
            link->front = link->rear = -1;
        }
        else
        {
            link->front = (link->front + 1) % MAX;
        }
        if (filaVacia(link))
        {
            link->tiempoEspera = 0;
        }
        else
        {
            link->tiempoEspera = link->tiempoEspera - transaccion;
        }
        // return;
    }
}

void imprimirFilaCircular(FilaCircular *link)
{

    if (filaVacia(link))
    {
        printf("\nLa fila Circular se encuentra vacia.\n");
        return;
    }
    printf("\nClientes de la fila Circular: \n");
    int i = link->front;

    while (i != link->rear)
    {
        printf("Cliente N°%d: %s, tipo de transaccion: %d \n", (i + 1), link->nombre[i], link->transaccion[i]);
        i = (i + 1) % MAX;
    }
    printf("Ultimo cliente %s, tipo de transaccion: %d \n", link->nombre[link->rear], link->transaccion[link->rear]);
}

void menu()
{
    FilaCircular link;
    inicializarFilaCircular(&link);
    int i, cantidadClientes, transaccion, opcion;
    char cliente[15];
    do
    {
        printf("1. Agregar Cliente\n");
        printf("2. Eliminar Cliente\n");
        printf("3. Imprimir Clientes\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
            case 1:
            {
                printf("Cuantos clientes desea agregar: ");
                scanf("%d", &cantidadClientes);

                for (i = 0; i < cantidadClientes; ++i)
                {
                    printf("Ingrese el nombre del cliente: \n");
                    scanf("%s", cliente);
                    int subOpcion;
                    printf("Tipos de Transaccion:\n");
                    printf("1. Retiro, tiempo aproximado: 5 Minutos\n");
                    printf("2. Deposito, tiempo aproximado: 2 Minutos\n");
                    printf("3. Consulta, tiempo aproximado: 4 Minutos\n");
                    printf("4. Actualizacion, tiempo aproximado: 5 Minutos\n");
                    printf("5. Pago, tiempo aproximado: 6 Minutos\n");
                    do
                    {
                        printf("Ingrese el tipo de operacion: \n");
                        scanf("%d", &subOpcion);
                    } while (subOpcion < 1 || subOpcion > 5);

                    switch (subOpcion)
                    {
                        case 1:
                        {
                            agregarCliente(&link, cliente, 5);
                        }
                            break;
                        case 2:
                        {
                            agregarCliente(&link, cliente, 2);
                        }
                            break;
                        case 3:
                        {
                            agregarCliente(&link, cliente, 4);
                        }
                            break;
                        case 4:
                        {
                            agregarCliente(&link, cliente, 5);
                        }
                            break;
                        case 5:
                        {
                            agregarCliente(&link, cliente, 6);
                        }
                            break;
                    }
                }
            }
                break;
            case 2:
            {
                if (filaVacia(&link))
                {
                    printf("Fila Vacia\n");
                }
                else
                {
                    printf("Cuantos clientes desea eliminar: ");
                    scanf("%d", &cantidadClientes);
                    for (i = 0; i < cantidadClientes; ++i)
                    {
                        eliminarCliente(&link);
                    }
                }
            }
            break;
            case 3:
            {
                imprimirFilaCircular(&link);
            }
                break;
            case 4:
            {
                printf("Gracias, saliendo... \n");
                exit(0);
            }
        }
        printf("Tiempo de espera actual: %d\n", link.tiempoEspera);
    } while (opcion != 4);
}

int main()
{
    menu();
    return 0;
}