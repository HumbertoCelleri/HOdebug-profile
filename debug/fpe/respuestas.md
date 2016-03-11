# wtpc2016: dia 4: Debug: Respuestas a los fpe

## Sin la bandera

###fpe1
Compila
### fpe2
Compila
### fpe3
No compila por que falta usar la libreria matemática -lm para linkear y que reconosca sqrt (No sqrtf, error de tippeo)

## Con la bandera -DTRAPFPE
Para que linkee se debe generar el objeto fpe_x87_sse_c.o. Primero se debe colocar la direccion correcta hacia el header.

Hay casos que te devuelven :
    1. nan, -nan
    2. 0 si sumas al maximo valor de 32bits
    3. Valores negativos dentro de sqrt()

###fpe1

### fpe2

### fpe3
