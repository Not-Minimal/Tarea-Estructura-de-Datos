//mati
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre_empresa[25];
} estructura_pilas;
int id = 700;
void leer_n_m(int *m, int *n);
void inicializar_ids(estructura_pilas pilas[11][6], int n, int m);
void push(estructura_pilas pilas[11][6], int n, int m);
void peek(estructura_pilas pilas[11][6], int n, int m);
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
            if (opcion_salida == 2)
            {
                system("cls");
                return;
            }
        }
        else
        {
            opcion_salida == 2;
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
            /*
                        estructura_pilas pila;
                        char buffer[25];

                        printf("Ingrese el nombre de la empresa: ");
                        fgets(buffer, sizeof(buffer), stdin);

                        // Elimina el salto de línea final de la cadena leída
                        if (buffer[strlen(buffer) - 1] == '\n')
                        {
                            buffer[strlen(buffer) - 1] = '\0';
                        }

                        // Copia la cadena leída en el campo nombre_empresa de la estructura
                        strcpy(pilas[10][1].nombre_empresa, buffer);
            */
            break;
        }
    }
}

void peek(estructura_pilas pilas[11][6], int n, int m)
{
    int opcion=0;
    int bandera_pila_vacia=0;
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
                bandera_pila_vacia=1;
                break;
            }
        }
        if (bandera_pila_vacia==0)
        {
            printf("Su pila esta vacia\n");
        }else{
            printf("Los datos de su pila son\n");
            printf("Nombre empresa: %s\n",pilas[i][opcion-1].nombre_empresa);
            printf("ID: %d\n",pilas[i][opcion-1].id);
        }
        
}
int main()
{

    int m, n;
    leer_n_m(&m, &n);
    estructura_pilas pilas[11][6];
    int i, j;

    // todo i <n  j<m
    inicializar_ids(pilas, n, m);

    system("cls");

    push(pilas, n, m);
    peek(pilas , n , m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", pilas[i][j].id);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
