from sys import stdin

def calculate(k, l, m, n, d) -> int:
    lista = [0] *d
    for i in range(d):
        if (i+1) % k == 0: lista[i] = 1
        elif (i+1) % l == 0: lista[i] = 1
        elif (i+1) % m == 0: lista[i] = 1
        elif (i+1) % n == 0: lista[i] = 1
    return sum(lista)


def main():
    k = stdin.readline().strip()
    SALIDA = []
    while len(k) != 0:
        k = int(k)
        l, m, n, d = [int(stdin.readline().strip()) for i in range(4)]
        SALIDA.append(str(calculate(k, l, m, n, d)))
        k = stdin.readline().strip()
    print("\n".join(SALIDA))
main()