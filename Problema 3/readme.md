# Enunciado
## Problema 3: Tiempo de Espera Estimado

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
### Agregar cliente y tipo de transacción(Aumenta tiempo de espera):
<img width="760" alt="Screenshot 2023-05-21 at 15 56 17" src="https://github.com/Not-Minimal/Tarea-Estructura-de-Datos/assets/58341096/9b860dc4-cf3d-42a0-b5ee-45a42abc84a2">

### Eliminar cliente(Descuenta tiempo de espera):
<img width="760" alt="Screenshot 2023-05-21 at 15 57 02" src="https://github.com/Not-Minimal/Tarea-Estructura-de-Datos/assets/58341096/a6e6533d-3945-439a-8370-cb69df92bd0d">

### Muestra los clientes en la fila, el tiempo de espera y cual es el ultimo cliente en ingresar, ademas del tipo de operacion que hara:
<img width="760" alt="Screenshot 2023-05-21 at 15 57 20" src="https://github.com/Not-Minimal/Tarea-Estructura-de-Datos/assets/58341096/cf16b2b6-98d3-4a96-8ee9-a60dd0f0ef70">

### Cierra Programa:
<img width="760" alt="Screenshot 2023-05-21 at 15 57 28" src="https://github.com/Not-Minimal/Tarea-Estructura-de-Datos/assets/58341096/a7415141-a2ff-42f5-8f30-b44f63c28c1e">


## Conclusion
El siguiente código presenta una implementación de una fila circular en lenguaje C.
Esta estructura de datos es ampliamente utilizada en programación y se caracteriza por tener una estructura circular,
donde el último elemento está conectado con el primero.
La fila implementada cuenta con algunas funcionalidades básicas,
tales como agregar y eliminar clientes, y una opción para imprimir los clientes en la fila.
Además, se incluye un menú para interactuar con la fila y agregar o eliminar clientes.

Para la implementación de la fila, se utilizan punteros y estructuras,
lo que permite una mayor eficiencia en la manipulación de los elementos.
Con esto, se logra simular el funcionamiento de una fila en un banco,
por ejemplo, con diferentes tipos de transacciones y tiempos de espera asociados.

Es importante mencionar que la fila circular tiene múltiples aplicaciones en el mundo de la programación,
desde la simulación de colas de espera en establecimientos de servicio,
hasta la implementación de algoritmos en inteligencia artificial.
En definitiva, el código presentado es una muestra de cómo la utilización de estructuras de datos
bien implementadas pueden facilitar la resolución de problemas complejos en el mundo de la programación.
