# encoding=UTF-8
__author__ = 'Alejandro'
import string

'''If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.'''

NUMEROS = {'one': 1,
           'two': 2,
           'three': 3,
           'four': 4,
           'five': 5,
           'six': 6,
           'seven': 7,
           'eight': 8,
           'nine': 9,
           'ten': 10,
           'eleven': 11,
           'twelve': 12,
           'thirteen': 13,
           'fourteen': 14,
           'fifteen': 15,
           'sixteen': 16,
           'seventeen': 17,
           'eighteen': 18,
           'nineteen': 19}

DENOMINACION = {'twenty': 20,
                'thirty': 30,
                'forty': 40,
                'fifty': 50,
                'sixty': 60,
                'seventy': 70,
                'eighty': 80,
                'ninety': 90,
                'hundred': 100,
                'thousand': 1000}


def formar_en_palabras(n):
    assert isinstance(n, int)
    if n > 1000:
        return "ERROR: Mayor que 1000"

    texto = ""
    while n > 0:
        if n == 1000:
            return "one thousand"
        elif 100 <= n < 1000:
            for clave, valor in NUMEROS.items():
                if str(n // 100) == str(valor):
                    texto = clave + ' hundred '
                    n -= (n // 100) * 100
                    break
        elif 20 <= n < 100:
            for clave, valor in DENOMINACION.items():
                if str(n - (n % 10)) == str(valor):
                    if texto != "":
                        texto += 'and '
                    texto += clave
                    n -= (n // 10) * 10
                    if n > 0:
                        texto += '-'
                    break
        elif 1 <= n < 20:
            for clave, valor in NUMEROS.items():
                if n == valor:
                    if texto[len(texto)-8:] == 'hundred ':
                        texto += 'and '
                    texto += clave
                    n = 0
        else:
            print('No deberia llegar hasta aqui')
    return texto


suma = 0
for i in range(1, 1001):
    palabras = formar_en_palabras(i)
    # print(i, palabras)
    for palabra in palabras.split():
        for letra in palabra:
            if letra in string.ascii_lowercase:
                suma += 1

print(suma)