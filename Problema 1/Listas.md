\section{Problema 1.- Listas lineales "simples"}

Escribir un programa C que implemente un menú al usuario (modo texto) que le permita ejecutar las siguientes operaciones:

1. Leer un conjunto de caracteres desde un archivo texto de entrada (.txt)

2. Generar una lista dinámicamente enlazada L con los caracteres leídos, indicando para cada carácter cuantas veces se encontraba repetido el mismo en el archivo fuente original.

Por ejemplo, si el archivo texto original es: "cuando cuentes cuentos, cuenta cuantos cuentos cuentas; porque si no cuentas cuantos cuentos cuentas, nunca sabrás cuantos cuentos sabes contar", entonces:

![](https://cdn.mathpix.com/cropped/2023_05_02_f3ba6df16250e9c2346ag-2.jpg?height=905&width=1177&top_left_y=694&top_left_x=230)

\begin{tabular}{|l|l|}
\hline letra & frecuencia \\
\hline c & 15 \\
\hline$u$ & 15 \\
\hline a & 12 \\
\hline $\mathrm{n}$ & 17 \\
\hline d & 1 \\
\hline$o$ & 11 \\
\hline & 19 \\
\hline e & 12 \\
\hline t & 13 \\
\hline s & 16 \\
\hline, & 2 \\
\hline$;$ & 1 \\
\hline p & 1 \\
\hline$r$ & 3 \\
\hline$q$ & 1 \\
\hline i & 1 \\
\hline b & 2 \\
\hline á & 1 \\
\hline
\end{tabular}

la lista a generar será:

![](https://cdn.mathpix.com/cropped/2023_05_02_f3ba6df16250e9c2346ag-2.jpg?height=173&width=1865&top_left_y=1754&top_left_x=127)

3. Ordenar la lista por frecuencia creciente

4. Ordenar la lista por frecuencia decreciente.

5. Buscar la presencia de un carácter específico (a leer) e indicar su frecuencia. 