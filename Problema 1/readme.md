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
El análisis del primer caso implica la creación de una estructura enlazada con dos variables: un carácter y un entero. Posteriormente, se envía un archivo en formato .txt, y si el archivo es nulo, el programa se termina. A continuación, se lee cuántos caracteres tiene el texto y se crea un array con todos los caracteres en el texto. La primera letra del array se envía al NODO. Luego, se comienza a eliminar el carácter que se ha enviado al NODO del array, mientras se cuenta cuántas veces se repite por cada eliminación. Se envía al NODO el número de veces que se elimina o aparece el carácter en el array, y se ordena en función del número de veces que se repite la letra en orden ascendente. Se extrae la letra más grande y se coloca en una nueva lista. Este proceso se lleva a cabo con la máxima profesionalidad y atención al detalle para garantizar la precisión y eficiencia en la ejecución del programa.

## Casos de Prueba

## Conclusion

Este código es un programa en lenguaje C que lee un archivo de texto, genera una lista dinámica con las letras encontradas y permite buscar un caracter específico en la lista. El programa es útil para procesar y analizar texto de manera eficiente. Además, el código utiliza estructuras de datos y punteros para manejar la lista dinámica de manera eficiente. Sin embargo, se podría mejorar el código agregando validación de entrada y manejo de errores para hacerlo más robusto. En general, es un buen ejemplo de cómo utilizar estructuras de datos y punteros en lenguaje C para resolver un problema específico.