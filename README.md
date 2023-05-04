# Tarea Estructura de Datos
Tarea en grupo de programación en C y elaboración de informe sobre problemas de estructuras de datos.

# Problema 1.- Listas lineales "simples"

Escribir un programa C que implemente un menú al usuario (modo texto) que le permita ejecutar las siguientes operaciones:

1. Leer un conjunto de caracteres desde un archivo texto de entrada (.txt)

2. Generar una lista dinámicamente enlazada L con los caracteres leídos, indicando para cada carácter cuantas veces se encontraba repetido el mismo en el archivo fuente original.

Por ejemplo, si el archivo texto original es: "cuando cuentes cuentos, cuenta cuantos cuentos cuentas; porque si no cuentas cuantos cuentos cuentas, nunca sabrás cuantos cuentos sabes contar", entonces:

| letra | frecuencia |
|-------|------------|
| c     | 15         |
| u     | 15         |
| a     | 12         |
| n     | 17         |
| d     | 1          |
| o     | 11         |
| 19    |            |
| e     | 12         |
| t     | 13         |
| s     | 16         |
| ,     | 2          |
| ;     | 1          |
| p     | 1          |
| r     | 3          |
| q     | 1          |
| i     | 1          |
| b     | 2          |
| á     | 1          |

La lista a generar será:

![](https://cdn.mathpix.com/cropped/2023_05_02_f3ba6df16250e9c2346ag-2.jpg?height=173&width=1865&top_left_y=1754&top_left_x=127)

1. Ordenar la lista por frecuencia creciente

2. Ordenar la lista por frecuencia decreciente.

3. Buscar la presencia de un carácter específico (a leer) e indicar su frecuencia.

## Analisis

## Casos de Prueba

## Conclusion

# Problema 2: Pilas para Ordenar Conteiner

En una bodega de un puerto se guarda la mercadería en contenedores (conteiners).

No es posible colocar más de $\mathrm{N}(\mathrm{N}>0)$ contenedores uno encima del otro dentro de la bodega; al mismo tiempo, no hay área para más de $M(M>0)$ pilas de contenedores. Cada contenedor tiene un código único, y además el nombre de la empresa propietaria del mismo.

Escriba un programa $C$ que permita gestionar el ingreso y salida de contenedores de manera manual; el programa debe desplegar por pantalla (modo texto) el movimiento de containers efectuado desde y hacia cada pila. Los valores de $\mathrm{N}$ y M son parámetros constantes indicados al inicio del programa.

Considere que la implementación de la pila debe ser estática (utilizar arrays), y debe implementar (y utilizar) las funciones básicas de una pila:

- Push: se añade un elemento al tope de la pila

- Pop: se elimina el elemento del tope de la pila

- Peek/TOS: retorna el valor consultado del nodo que está en el tope de la pila.

Note que para retirar un contenedor es necesario retirar los contenedores que están encima de él y colocarlos en otra pila (esto obliga a contar con un espacio para una pila de contenedores auxiliar, que también debe reflejar sus movimientos en Pantalla y es parte de las M pilas disponibles)

Obs: Son rangos de valores válidos para $\mathrm{M}$ y $\mathrm{N}$ los siguientes: $0<\mathrm{M}<7 ; 0<\mathrm{N}<12$

![](https://cdn.mathpix.com/cropped/2023_05_02_f3ba6df16250e9c2346ag-3.jpg?height=648&width=811&top_left_y=1663&top_left_x=142)

Se supone que las $M$ pilas de contenedores están distribuidas alrededor del pasillo central de acceso.

## Analisis

Programa para ordenar contenedores con pilas.

Inicialmente, se leerán los valores de "n", que es el tamaño máximo de la pila (0 < n < 12), y "m", que es la cantidad de pilas (0 < m < 7). Luego, se definirá la matriz para la bodega con una estructura.

```
typedef struct [
int id;
char[25] nombre_empresa;
] estructura_bodega;
estructura_bodega bodega[n][m];
```

A continuación, se desplegará un menú con las siguientes opciones:

- Push a pila: se le preguntará al usuario en cuál de las "m" pilas desea ingresar los datos (si hay más de una).
- Pop a pila: se le preguntará al usuario de cuál de las "m" pilas desea eliminar los datos (en caso de haberlos), y luego se le preguntará cuál de las "n" pilas desea eliminar.
- Peek a pila: se le preguntará al usuario de cuál de las "m" pilas desea ver el tope.
- Mostrar los datos de una pila en específico: aunque no está en el enunciado, creo que es necesaria para que se pueda hacer el pop de buena manera. Al pedir el ID a eliminar, el usuario debe saber cuál es el ID y su empresa.

Dado que es un array y la memoria existe aunque no esté leída, y esos datos pueden tener basura, rellenaremos los IDs con -1 cuando no haya datos y diremos que los borramos. Por ejemplo, si la pila tiene 2 elementos y borramos la cabeza, los IDs quedarían así: pila[0].id = 3234 y pila[1].id = -1.

Las siguientes son las funciones principales:

- Push (recibe la estructura): se leen los datos (se le pregunta cuál pila del 1 al 7 como máximo desea hacer push, si hay más de 1) y se retorna la estructura.
- Pop (recibe la estructura): estamos evaluando dos opciones para esta función:

    - Opción 1: se lee cuál se va a eliminar (se le pregunta el ID del contenedor y luego se lo busca). Si hay espacio suficiente en las demás pilas para usar de auxiliar, se mueven los datos a otras pilas o pila y se borra el ID actual. Luego, los datos enviados a las demás pilas rellenan nuevamente el hueco.

    - Opción 2: usar una pila auxiliar de tamaño máximo 11 para guardar los datos, borrar el que se borra y luego los datos vuelven a la pila original.

- Peek (recibe la estructura): se pregunta cuál de las "m" pilas desea ver el tope y se muestra el final de ella, que será el tope.
- Función para mostrar el movimiento de las pilas: se creará una función para mostrar cómo se mueven las pilas, tal como se indica en el enunciado.
- Función para mostrar los datos de una pila específica: se lee cuál de las "m" pilas desea mostrar y se muestran los datos con un printf y un for.

## Casos de Prueba

## Conclusion

# Problema 3: Tiempo de Espera Estimado

Implemente un programa $\mathrm{C}$ que reciba los datos de personas en una fila circular implementada en un array para los clientes de un banco: nombre y conjunto de transacciones a realizar.

Se requiere informar al público del tiempo estimado de permanencia de cualquier persona en la cola, si se conocen los tiempos estimados para cada tipo de transacción:

| Tipo          | Minutos |
|---------------|---------|
| Retiro        | 5       |
| Depósito      | 2       |
| Consulta      | 4       |
| Actualización | 5       |
| Pagos         | 6       |

Escriba un programa $\mathrm{C}$ completo que informe al público general el tiempo estimado de espera para la cola, basándose en el total de personas y los trámites que vienen a ejecutar.

Suponga:

1. Que se ingresará un nodo para cada trámite de cada persona que se informa al ingresar a la cola,

2. Cada vez que una persona ingresa a la cola la información de tiempo estimado de espera se actualiza.

3. En forma similar, cuando una persona sale de la cola, su tiempo de trámite afecta al valor presupuestado y ese cambio se debe informar al público.

## Analisis

Programa para controlar la lista de clientes y los tiempos de espera en un banco.
Para lograrlo, se utilizará una lista enlazada con sus respectivos nodos, haciendo uso de estructuras y punteros, así como de memoria dinámica y de librerías como stdio.h, stdlib.h y string.h.
Se define una variable global "max", que no cambiará. Se crea una estructura de fila llamada "fila circular" con las variables "front", "rear", "nombre" y "tipo de transacción".
Se definen los prototipos básicos para el uso de la fila circular:

```
Void inicializarFilaCircular(FilaCircular *link)
Int filaVacía(FilaCircular *link)
Int FilaLlena(FilaCircular *link)
Void agregarCliente(FilaCircular *link, char *nombre, int transacción)
Int eliminarCliente(FilaCircular *link)
Void imprimirFilaCircular(FilaCircular *link) 
Int calculoEspera(FilaCircular *link)
```

1. Se encarga de iniciar la fila circular.
2. Verifica si la fila está vacía o no.
3. Verifica si la fila está llena o no.
4. Permite agregar nuevos clientes a la fila con su debido nombre y tipo de transacción.
5. Permite eliminar clientes de la fila.
6. Imprime la fila de clientes y sus tipos de transacciones. Hace uso de la función "fila vacía" para determinar si sigue con el código o no.
7. Se encarga de mantener un contador de tiempo para la espera de los clientes, teniendo en cuenta las funciones de agregar y eliminar clientes.
8. Finalmente, en la función "main", se hace uso de las funciones, pasando los parámetros necesarios como nombre y tipo de transacción.

## Casos de Prueba

## Conclusion