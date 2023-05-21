//mati
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
typedef struct
{
    int id;
    char nombre_empresa[25];
} estructura_pilas;
int id = 700;
void leer_n_m(int *m, int *n);
void inicializar_ids(estructura_pilas pilas[12][7], int n, int m);
void push(estructura_pilas pilas[12][7], int n, int m);
void peek(estructura_pilas pilas[12][7], int n, int m);
void imprimir_container(estructura_pilas pilas[12][7], int n, int m);
void pop(estructura_pilas pilas[12][7], int n, int m);
void mostrar_pila(estructura_pilas pilas[12][7], int n , int m);

void leer_n_m(int *m, int *n)
{

    do
    {
        printf("Ingrese la cantidad de pilas \nvalores validos 0<m<=7\n");
        scanf("%d", &*m);
        fflush(stdin);
        if (*m <= 0 || *m > 7)
        {
            system("cls");
            printf("Valor invalido reingrese dato\n");
        }
    } while (*m <= 0 || *m > 7);
    system("cls");
    do
    {
        printf("Ingrese el tamanio de las pilas \nvalores validos 0<n<=12\n");
        scanf("%d", &*n);
        fflush(stdin);
        if (*n <= 0 || *n > 12)
        {
            system("cls");
            printf("Valor invalido reingrese dato\n");
        }
    } while (*n <= 0 || *n > 12);
    system("cls");
}

void inicializar_ids(estructura_pilas pilas[12][7], int n, int m)
{
    int i, j, x = -1;
    //? asi se trata la lectura pero desde abaj
    for (j = 0; j < m; j++)
    {
        for (i = n - 1; i >= 0; i--)
        {
            pilas[i][j].id = x;
        }
    }
}

void push(estructura_pilas pilas[12][7], int n, int m)
{
    int opcion = 0;
    int opcion_salida = 0;
    int bandera_espacio = 0;
    int i, j;
    do
    {
        printf("Ingrese a que pila quiere agregar un contenedor\n");
        printf("Existen %d pilas\n", m);
        do
        {
            scanf("%d", &opcion);
            fflush(stdin);
            if (opcion <= 0 || opcion > m)
            {
                system("cls");
                printf("Valor invalido ingrese denuevo\n");
                printf("Ingrese a que pila quiere agregar un contenedor\n");
                printf("Existen %d pilas\n", m);
            }

        } while (opcion <= 0 || opcion > m);

        for (i = n - 1; i >= 0; i--)
        {
            if (pilas[i][opcion - 1].id == -1)
            {
                bandera_espacio = 1;
                break;
            }
        }

        if (bandera_espacio == 0)
        {

            system("cls");
            printf("Su pila elegida esta llena \n");
            opcion_salida=2;
            system("pause");
            return;
        }

    } while (opcion_salida == 1);

    for (i = n - 1; i >= 0; i--)
    {
        if (pilas[i][opcion - 1].id == -1)
        {
            pilas[i][opcion - 1].id = id;
            id = id + 23;
            printf("Ingrese el nombre de la empresa del contenedor\n");
            fgets(pilas[i][opcion - 1].nombre_empresa, 25, stdin);
            printf("Su nombre ingresado es %s", pilas[i][opcion - 1].nombre_empresa);
            fflush(stdin);

            break;
        }
    }
}

void peek(estructura_pilas pilas[12][7], int n, int m)
{
    int opcion = 0;
    int bandera_pila_vacia = 0;
    int i;
    printf("Ingrese a que pila quiere consultar su peek\n");
    printf("Existen %d pilas\n", m);
    do
    {
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion <= 0 || opcion > m)
        {
            system("cls");
            printf("Valor invalido ingrese denuevo\n");
            printf("Ingrese a que pila quiere consultar su peek\n");
            printf("Existen %d pilas\n", m);
        }

    } while (opcion <= 0 || opcion > m);

    for (i = n - 1; i >= 0; i--)
    {
        if (pilas[i][opcion - 1].id != -1)
        {
            bandera_pila_vacia = 1;
            break;
        }
    }
    if (bandera_pila_vacia == 0)
    {
        printf("Su pila esta vacia\n");
    }
    else
    {
        printf("Los datos de su pila son\n");
        printf("Nombre empresa: %s\n", pilas[i][opcion - 1].nombre_empresa);
        printf("ID: %d\n", pilas[i][opcion - 1].id);
    }
}

void imprimir_container(estructura_pilas pilas[12][7], int n, int m)
{

    int i, j;

    char cuadrado = 254;
    char linea_parada = 179;
    char guion_alto = 238;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            /*
            if (j == 0)
            {
                printf("%c", linea_parada);
            }
            */
            if (pilas[i][j].id != -1)
            {
                printf("%c ", cuadrado);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    /*
    for (i = 0; i < (m * 2) - 1; i++)
    {
        printf("%c", guion_alto);
    }
    printf("\n");
    */
}

void mostrar_pila(estructura_pilas pilas[12][7], int n , int m){

    int i, j;
    int opcion = 0;
    printf("Ingrese de que pila quiere ver sus datos\n");
    printf("Existen %d pilas\n", m);
    do
    {
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion <= 0 || opcion > m)
        {
            system("cls");
            printf("Valor invalido ingrese denuevo\n");
            printf("Ingrese de que pila quiere ver sus datos\n");
            printf("Existen %d pilas\n", m);
        }

    } while (opcion <= 0 || opcion > m);
    opcion--;
    system("cls");
    int bandera_vacio=0;
    for ( i = 0; i < n; i++)
    {
        if (pilas[i][opcion].id!= -1)
        {
            bandera_vacio=1;
             printf("Id: %d\n",pilas[i][opcion].id);
            printf("Nombre empresa: %s\n",pilas[i][opcion].nombre_empresa);
        }
        
       
    }
    if (bandera_vacio==0)
    {
        printf("Su pila esta vacia\n");
    }
    
}

void pop(estructura_pilas pilas[12][7], int n, int m)
{

    int i, j;
    int opcion = 0;
    printf("Ingrese de que pila quiere eliminar\n");
    printf("Existen %d pilas\n", m);
    do
    {
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion <= 0 || opcion > m)
        {
            system("cls");
            printf("Valor invalido ingrese denuevo\n");
            printf("Ingrese a que pila quiere consultar su peek\n");
            printf("Existen %d pilas\n", m);
        }

    } while (opcion <= 0 || opcion > m);
    system("cls");
    opcion = opcion - 1;
    int contador_datos = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (pilas[i][opcion].id != -1)
        {
            contador_datos++;
        }
    }
    if (contador_datos == 0)
    {
        printf("Su pila esta vacia\n");
        return;
    }

    int lugar_eliminar;
    printf("Ingrese el contenedor que desea eliminar\n");
    printf("Enumerados de abajo hacia arriba\n");
    printf("Existen %d contenedores en su pila elegida\n", contador_datos);
    scanf("%d", &lugar_eliminar);
    fflush(stdin);
    system("cls");

    // Comprobar si lugar_eliminar es la cabeza de la pila
    if (lugar_eliminar == contador_datos)
    {
        imprimir_container(pilas, n, m);
        struct timespec tiempo;
        tiempo.tv_sec = 0;          // Segundos
        tiempo.tv_nsec = 750000000; // Nanosegundos (0.75 segundos en nanosegundos)
        nanosleep(&tiempo, NULL);
        system("cls");
        strcpy(pilas[n - lugar_eliminar][opcion].nombre_empresa, " ");
        pilas[n - lugar_eliminar][opcion].id = -1;
        return;
    }

    // si no es cabeza hacemos lo otro
    if (lugar_eliminar <= 0 || lugar_eliminar > contador_datos)
    {
        printf("Valor inválido, no existe ese container\n");
        return;
    }

    int contador_espacio_libre = 0;
    int espacios_libres_pilas[m];
    int devolver[m];
    for (i = 0; i < m; i++)
    {
        espacios_libres_pilas[i] = 0;
        devolver[i]=0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (pilas[i][j].id == -1 && j != opcion)
            {
                contador_espacio_libre++;
                espacios_libres_pilas[j]++;
            }
        }
    }

    if (contador_espacio_libre < contador_datos - lugar_eliminar)
    {
        printf("No hay suficiente espacio para mover los datos en la pila\n");
        return;
    }

    int indice_eliminar = n - lugar_eliminar;
    int k, l;
    int indice_tope_actual;
    for (i = 0; i < n; i++)
    {
        if (pilas[i][opcion].id != -1)
        {
            indice_tope_actual = i;
            break;
        }
    }

    int bandera_finalizar = 0;
    for (i = 0; i < m; i++)
    {
        if (espacios_libres_pilas[i] > 0 && i != opcion)
        {

            while (espacios_libres_pilas[i] != 0)
            {
                for (k = n - 1; k >= 0; k--)
                {
                    if (pilas[k][i].id == -1)
                    {
                        imprimir_container(pilas, n, m);
                        struct timespec tiempo;
                        tiempo.tv_sec = 0;          // Segundos
                        tiempo.tv_nsec = 750000000; // Nanosegundos (0.75 segundos en nanosegundos)
                        nanosleep(&tiempo, NULL);
                        system("cls");
                        pilas[k][i].id = pilas[indice_tope_actual][opcion].id;
                        pilas[indice_tope_actual][opcion].id = -1;

                        strcpy(pilas[k][i].nombre_empresa, pilas[indice_tope_actual][opcion].nombre_empresa);
                        strcpy(pilas[indice_tope_actual][opcion].nombre_empresa, " ");
                        imprimir_container(pilas, n, m);
                        system("cls");
                        indice_tope_actual++;
                        espacios_libres_pilas[i]--;
                        devolver[i]++;
                        break;
                    }
                }

                if (indice_tope_actual == indice_eliminar)
                {
                    imprimir_container(pilas, n, m);
                    struct timespec tiempo;
                    tiempo.tv_sec = 0;          // Segundos
                    tiempo.tv_nsec = 750000000; // Nanosegundos (0.75 segundos en nanosegundos)
                    nanosleep(&tiempo, NULL);
                    system("cls");
                    strcpy(pilas[indice_eliminar][opcion].nombre_empresa, " ");
                    pilas[indice_eliminar][opcion].id = -1;
                    bandera_finalizar = 1;
                    imprimir_container(pilas, n, m);
                    system("cls");
                    break;
                }
            }
        }
        if (bandera_finalizar == 1)
        {
            break;
        }
    }
    
    for ( i = m-1; i >= 0; i--)
    {
        if (devolver[i]> 0 && i!=opcion)
        {
            while (devolver[i]!= 0)
            {
                int contador=0;
                for ( k = 0; k<n; k++)
                {
                    if (pilas[k][i].id!= -1 )
                    {
                        imprimir_container(pilas, n, m);
                        struct timespec tiempo;
                        tiempo.tv_sec = 0;          // Segundos
                        tiempo.tv_nsec = 750000000; // Nanosegundos (0.75 segundos en nanosegundos)
                        nanosleep(&tiempo, NULL);
                        system("cls");
                        pilas[indice_tope_actual][opcion].id=pilas[k][i].id;
                        pilas[k][i].id= -1;
                        strcpy(pilas[indice_tope_actual][opcion].nombre_empresa, pilas[k][i].nombre_empresa);
                        strcpy(pilas[k][i].nombre_empresa, " ");
                        imprimir_container(pilas, n, m);
                        system("cls");
                        indice_tope_actual--;
                        contador++;
                    }
                    if (contador==devolver[i])
                    {
                        devolver[i]=0;
                        break;
                    }
                    
                    
                }
                
            }
            
        }
        
    }
    
}

int main()
{

    int m, n;
    leer_n_m(&m, &n);
    estructura_pilas pilas[12][7];
    int i, j;

    // todo i <n  j<m
    inicializar_ids(pilas, n, m);

    system("cls");
    int bandera_print=0;
    int opcion_menu = 0;
    do
    {
        printf("Ingrese 1 para hacer push\n");
        printf("Ingrese 2 para hacer pop\n");
        printf("Ingrese 3 para hacer peek\n");
        printf("Ingrese 4 para mostar los id y nombre de una pila en especifica\n");
        printf("Ingrese 5 para salir\n");
        scanf("%d", &opcion_menu);
        fflush(stdin);
        system("cls");
        switch (opcion_menu)
        {
        case 1:
            push(pilas, n, m);
            system("cls");
            break;

        case 2:
            pop(pilas, n, m);
            break;

        case 3:
            peek(pilas, n, m);
            break;

        case 4:
            mostrar_pila(pilas,n,m);
            break;

        case 5:
            printf("Cerrando progama\n");
            bandera_print=1;
            break;

        default:
            printf("Valor invalido reingrese dato\n");
            break;
        }

        if (bandera_print==0)
        {
            imprimir_container(pilas, n, m);
        }
        
        
    } while (opcion_menu != 5);

    system("pause");
    return 0;
}
