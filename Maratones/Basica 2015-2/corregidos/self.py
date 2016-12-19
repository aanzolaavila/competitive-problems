import bisect


def d(n):
    if n > 0:
        return n + sum([int(c) for c in str(n)])
    return None

def self(n):
    for i in range(n-9*len(str(n)),n):
        if d(i) == n: return True
    return False

def generate():
    global lista
    gen = 1
    actual = d(1)
    while len(lista) < 10**7:
        while actual < 10**6:
            n = d(actual)
            lista.append(n)
            actual = n


lista = []


def bina(a, x) -> bool:
    b = bisect.bisect(a, x)
    if a[b] == x: return True
    return False


def main():
    global lista
    #generate()
    #lista = list(set(lista))
    #lista.sort()
    # print(lista)
    SALIDA = [str(i) for i in range(1,10 ** 6 + 1) if not self(i)]
    print("\n".join(SALIDA))


main()
