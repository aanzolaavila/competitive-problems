from sys import stdin

def a(n) -> int:
    global lista
    if n in lista: return lista[n]
    lista[n] = a(n-1) + a(n-2)
    return lista[n]

lista = {1:1, 2:2}

def main():
    n = int(stdin.readline().strip())
    SALIDA = []
    while n != 0:
        SALIDA.append(str(a(n)))
        n = int(stdin.readline().strip())
    print("\n".join(SALIDA))
main()
