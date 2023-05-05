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
