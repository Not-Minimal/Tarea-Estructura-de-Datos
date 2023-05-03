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