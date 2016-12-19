__author__ = 'Alejandro Anzola'

'''Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?'''

DIMENSIONES = 1001

cuadricula = [[0 for x in range(DIMENSIONES)] for x in range(DIMENSIONES)]


def generar_cuadricula(c, DIM):
    c[DIM // 2][DIM // 2] = 1

    valor = 2

    dx = 1
    dy = 0
    segmento_longitud = 1

    x = DIM // 2 + 1
    y = DIM // 2 + 1
    segmento_pasados = 0

    for k in range(DIM ** 2 - 1):
        x += dx
        y += dy
        segmento_pasados += 1
        c[y - 1][x - 1] = valor
        # print(valor)
        valor += 1

        if segmento_pasados == segmento_longitud:
            segmento_pasados = 0

            buffer = dx
            dx = -dy
            dy = buffer

            if dy == 0:
                segmento_longitud += 1


generar_cuadricula(cuadricula, DIMENSIONES)

suma = -1

for i in range(DIMENSIONES):
    suma += cuadricula[i][i]

for i in range(DIMENSIONES):
    suma += cuadricula[i][DIMENSIONES - 1 - i]

print(suma)
