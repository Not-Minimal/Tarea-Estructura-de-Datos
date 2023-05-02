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