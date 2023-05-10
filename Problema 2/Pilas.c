// Mati
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre_empresa[25];
} estructura_pilas;

void leer_n_m(int *m, int *n);
void inicializar_ids(estructura_pilas pilas[11][6], int n, int m);
void push(estructura_pilas pilas[11][6], int n, int m);
void leer_n_m(int *m, int *n)
{

    do
    {
        printf("Ingrese la cantidad de pilas \nvalores validos 0<m<7\n");
        scanf("%d", &*m);
        fflush(stdin);
        if (*m <= 0 || *m >= 7)
        {
            system("cls");
            printf("Valor invalido reingrese dato\n");
        }
    } while (*m <= 0 || *m >= 7);
    system("cls");
    do
    {
        printf("Ingrese el tamanio de las pilas \nvalores validos 0<n<12\n");
        scanf("%d", &*n);
        fflush(stdin);
        if (*n <= 0 || *n >= 12)
        {
            system("cls");
            printf("Valor invalido reingrese dato\n");
        }
    } while (*n <= 0 || *n >= 12);
    system("cls");
}

void inicializar_ids(estructura_pilas pilas[11][6], int n, int m)
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

void push(estructura_pilas pilas[11][6], int n, int m)
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
            printf("presione 1 para elegir otra pila\n");
            printf("Presione 2 para volver al Menu\n");

            do
            {
                scanf("%d", &opcion_salida);
                fflush(stdin);
                if (opcion_salida > 2 || opcion_salida < 1)
                {
                    system("cls");
                    printf("Valor invalido reingrese dato\n");
                    printf("Su pila elegida esta llena \n");
                    printf("presione 1 para elegir otra pila\n");
                    printf("Presione 2 para volver al Menu\n");
                }

            } while (opcion_salida > 2 || opcion_salida < 1);
            if (opcion_salida==2)
            {
                system("cls");
                return;
            }
            
        }else{
            opcion_salida==2;
        }

    } while (opcion_salida==1);
}
int main()
{

    int m, n;
    leer_n_m(&m, &n);
    estructura_pilas pilas[11][6];
    int i, j;

    // todo i <n  j<m
    inicializar_ids(pilas, n, m);
    push(pilas,n,m);
    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", pilas[i][j].id);
        }
        printf("\n");
    }
*/
    system("pause");
    return 0;
}
