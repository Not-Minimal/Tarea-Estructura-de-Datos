//Primero Creare una Fila Circular Comun y corriente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 //Tamaño maximo de la fila

//Estructura de la fila
typedef struct{
    int front, rear;
    char* nombre[MAX];
    char* transaccion[MAX];
}FilaCircular;

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

//Agregar un nuevo elemento a la fila›
void agregarElemento(FilaCircular *link, char *nombre, int transaccion){

    if (filaLlena(link)){
        return;
    } else {
        link->rear = (link->rear + 1) % MAX;
        link->nombre[link->rear] = (char*) malloc(strlen(nombre) + 1);
        strcpy(link->nombre[link->rear], nombre);
        link->transaccion[link->rear] = transaccion;
        if (link->front == -1) {
            link->front = link->rear;
        }
    }
}

//Eliminar Elemento de la Lista
int eliminarElemento(FilaCircular *link ){
    int valor;
    if (filaVacia(link)){
        return 0;
    } else{
        valor = link->arreglo[link->front];
        if (link->front == link->rear){
            link->front = link->rear = -1;
        } else{
            link->front = (link->front + 1) % MAX;
        } return valor;
    }
}

void imprimirFilaCircular(FilaCircular *link){
    if (filaVacia(link)){
        printf("La fila Circular se encuentra vacia. \n");
        return;
    }
    printf("\nElementos de la fila Circular: \n");
    int i = link->front;

    while (i != link->rear){
        printf("%d ", link->arreglo[i]);
        i = (i + 1) % MAX;
    }
    printf("%d \n", link->arreglo[link->rear]);

}


int main(){

    FilaCircular link;
    inicializarFilaCircular(&link);
    //agregarElemento(&link, 1);
    //agregarElemento(&link, 2);
    //agregarElemento(&link, 3);
    //agregarElemento(&link, 4);

    if (eliminarElemento(&link) == 0){
        printf("La Fila esta vacia");
    }

    printf("%d ", eliminarElemento(&link));
    printf("%d ", eliminarElemento(&link));

    agregarElemento(&link, 5);
    agregarElemento(&link, 6);

    imprimirFilaCircular(&link);


    return 0;
}
