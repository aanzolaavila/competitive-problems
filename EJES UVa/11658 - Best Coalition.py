# -*- coding: utf-8 -*-
__author__ = 'Alejandro Anzola'

from sys import stdin

def best_coalition(N, X, lista) -> float:
    actual = lista[X]
    if actual >= 50:
        return 100.00

    del lista[X]
    lista.sort()
    mejor = 0.00

    for inicio in range(N):
        for final in range(inicio+1, N-1):
            suma = actual + sum(lista[inicio:final])
            if suma > 50:
                p = float((actual * 100.00) / float(suma))
                if p > mejor: mejor = p
            suma = actual + lista[inicio]+lista[final]
            if suma > 50.0:
                p = float((actual * 100.00) / float(suma))
                if p > mejor: mejor = p

    return mejor

def main():
    SALIDA = []

    finalizado = False
    while not finalizado:
        n, x = [int(c) for c in stdin.readline().strip().split()]
        if n == 0 or x == 0:
            finalizado = True
            continue

        lista = [float(stdin.readline().strip()) for x in range(n)]

        SALIDA.append(best_coalition(n, x-1, lista))

    for e in SALIDA:
        print("%.2f" % round(e , 2))

main()
