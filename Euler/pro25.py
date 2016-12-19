def fibonacci(numero):
    if numero == 1: return 1
    if numero == 2: return 1
    fn1 = 1
    fn2 = 0
    n = 1
    while n < numero:
        va = fn1 + fn2
        fn2 = fn1
        fn1 = va
        n += 1

    return fn1


def digitos(numero):
    if numero == 0: return 1
    c = 0
    while numero > 0:
        numero = (numero - (numero % 10)) / 10
        c += 1

    return c


n = 1
while digitos(fibonacci(n)) != 1000:
    n += 1

print(n)
