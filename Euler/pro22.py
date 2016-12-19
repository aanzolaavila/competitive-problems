# encoding=UTF-8
__author__ = 'Alejandro'
import string

'''Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?'''

archivo = open("./extras/p022_names.txt", 'r')
LISTA = archivo.read()
archivo.close()

indice = 1
totalPuntos = 0

for nombre in sorted(LISTA[1: len(LISTA) - 1].split('\",\"')):
    puntosNombre = 0
    for letra in nombre:
        puntosNombre += string.ascii_uppercase.index(letra) + 1
    totalPuntos += puntosNombre * indice
    indice += 1

print(totalPuntos)
