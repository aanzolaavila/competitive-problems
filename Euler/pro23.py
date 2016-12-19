# encoding=UTF-8
__author__ = 'Alejandro'
import math

'''A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.'''

lista_numeros_abundantes = []


def es_abundante(n):
    assert isinstance(n, int)
    if n < 12:
        return False

    sum = 1
    sqrt_n = math.floor(math.sqrt(n))

    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            sum += i + n / i

    if sqrt_n ** 2 == n:
        sum -= sqrt_n

    if sum > n:
        return True
    else:
        return False


def es_suma_de_dos_abundantes(n):
    if n < 24:
        return False
    for i in range(12, n // 2 + 1):
        if n - i > 0:
            if lista_numeros_abundantes[i - 1] and lista_numeros_abundantes[n - i - 1]:
                return True
    return False


sumaTotal = 0

for numero in range(1, 28124):
    if es_abundante(numero):
        lista_numeros_abundantes.append(True)
    else:
        lista_numeros_abundantes.append(False)

for numero in range(1, 28124):
    if not (es_suma_de_dos_abundantes(numero)):
        sumaTotal += numero
        '''if iter % 100 == 0:
            print(n)
        iter += 1'''

print(sumaTotal)
