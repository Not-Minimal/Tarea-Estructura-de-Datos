//Primero Creare una Fila Circular Comun y corriente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 //Tamaño maximo de la fila
int tiempoEspera = 0;

//Estructura de la fila
typedef struct{
    int front, rear;
    char* nombre[MAX];
    int transaccion[MAX];
    int tiempoEspera;
}FilaCircular;

//Prototipo de Funciones
void inicializarFilaCircular(FilaCircular *link);
int filaVacia(FilaCircular *link);
int filaLlena(FilaCircular *link);
void agregarCliente(FilaCircular *link, char *nombre, int transaccion);
int eliminarCliente(FilaCircular *link);
void imprimirFilaCircular(FilaCircular *link);
int calcularEspera(FilaCircular *link);

//Iniciar la Fila por Defecto
void inicializarFilaCircular(FilaCircular *link){
    link->front = link->rear = -1;
}

//Verificar si la Fila esta vacia
int filaVacia(FilaCircular *link){
    return (link->front == -1);
}

//Verificar si la fila esta llena
int filaLlena(FilaCircular *link){
    return ((link->rear+1) % MAX == link->front);
}

//Agregar un nuevo Clientes a la fila›
void agregarCliente(FilaCircular *link, char *nombre, int transaccion){

    if (filaLlena(link)){
        return;
    } else {
        link->rear = (link->rear + 1) % MAX;
        link->nombre[link->rear] = (char*) malloc(strlen(nombre) + 1);
        strcpy(link->nombre[link->rear], nombre);
        link->transaccion[link->rear] = transaccion;
        link->tiempoEspera = link->tiempoEspera + transaccion;
        if (link->front == -1) {
            link->front = link->rear;
        }
    }
}

//Eliminar Clientes de la Lista
int eliminarCliente(FilaCircular *link){

    if (filaVacia(link)){
        return 0;
    } else{
        char* nombre = link->nombre[link->front];
        int transaccion = link->transaccion[link->front];
        printf("Atendiendo a %s en transaccion N°%d. \n", nombre, transaccion);
        free(nombre);
        if (link->front == link->rear){
            link->front = link->rear = -1;
        } else{
            link->front = (link->front + 1) % MAX;
        }
        if (filaVacia(link)){
            link->tiempoEspera = 0;
        } else{
            link->tiempoEspera = link->tiempoEspera - transaccion;
        }
        //return;
    }
}

void imprimirFilaCircular(FilaCircular *link){

    if (filaVacia(link)){
        printf("\nLa fila Circular se encuentra vacia.\n");
        return;
    }
    printf("\nClientes de la fila Circular: \n");
    int i = link->front;

    while (i != link->rear){
        printf("Cliente N°%d: %s, tipo de transaccion: %d \n",(i+1), link->nombre[i], link->transaccion[i]);
        i = (i + 1) % MAX;
    }
    printf("Ultimo cliente %s, tipo de transaccion: %d \n", link->nombre[link->rear], link->transaccion[link->rear]);
}

int main(){

    FilaCircular link;
    inicializarFilaCircular(&link);
    printf("Tiempo de espera inicio: %d", tiempoEspera);
    //agregarCliente(&link, "Diego Aguilera", 5);
    //agregarCliente(&link, "Matias Arenas", 2);
    //agregarCliente(&link, "Saul Munoz", 3);
    //agregarCliente(&link, "Deadpool", 4);
    //eliminarCliente(&link);


    link.tiempoEspera;

    /*
     if (eliminarCliente(&link) == 0){
        printf("La Fila esta vacia");
        }
     */

    imprimirFilaCircular(&link);
    printf("Tiempo de espera Final: %d", link.tiempoEspera);

    return 0;
}
