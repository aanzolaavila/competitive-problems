__author__ = 'skinman95'

from sys import stdin

def main():
    SALIDA, n = "", int(stdin.readline().strip())
    while n > 0:
        palabra, n = stdin.readline().strip(), n-1
        SALIDA += (palabra if len(palabra) <= 10 else (palabra[0] + str(len(palabra)-2) + palabra[-1])) + '\n'
    print(SALIDA)
main()