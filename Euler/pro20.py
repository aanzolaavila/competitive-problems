'''
n! means n * (n - 1)  ...  3 * 2 * 1

For example, 10! = 10 * 9  ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!'''


def factorial(numero) -> int:
    assert isinstance(numero, int)
    r = 1
    i = 1
    while i <= numero:
        r *= i
        i += 1

    return r


def suma_digitos(numero) -> int:
    assert isinstance(numero, int)
    res = 0
    while numero > 0:
        res += numero % 10
        numero = (numero - (numero % 10)) / 10

    return res


print(suma_digitos(factorial(100)))
