__author__ = 'skinman95'

from sys import stdin

DICT = ("AOYEUI")

def vowels(cadena):
    cadena, vow = cadena.upper(), ""
    for letra in cadena:
        if letra not in DICT: vow += '.' + letra.lower()
    return vow

def main():
    line, SALIDA = stdin.readline().strip(), ""
    while len(line) != 0:
        SALIDA += vowels(line) + '\n'
        line = stdin.readline().strip()
    print(SALIDA)
main()