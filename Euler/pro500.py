__author__ = 'Alejandro'
import math
'''The number of divisors of 120 is 16.
In fact 120 is the smallest number having 16 divisors.

Find the smallest number with 2^500500 divisors.
Give your answer modulo 500500507.'''

import decimal

numero_divisores = 2**500500

def cantidad_de_divisores(n):
    c = 2
    lim = n / 2 + 1
    divisor = 2
    while lim > divisor:
        if n % divisor == 0:
            c += 1
            print(c, divisor)
        divisor += 1
    return c

def elevar(n, x, digitos):
    resultado = 1
    while x > 0:
        if x % 2 == 1:
            resultado *= n
            resultado %= 10**digitos
        n *= n
        n %= 10**digitos
        x //= 2
    return resultado
'''
i = (numero_divisores - 16) // 4
n = 15 * elevar(2, i+3, len(str(500500507))+1)
print(n % 500500507)
'''
for i in range(361):
    print(i, cantidad_de_divisores(i))

print(42875, cantidad_de_divisores(42875))