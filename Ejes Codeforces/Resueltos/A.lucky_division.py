from sys import stdin
import itertools

lista = []

def generate_lucky(n) -> None:
    global lista
    good = set("47")
    lista.extend([c for c in range(4,n+1) if set(str(c)) <= good])

def is_almost_lucky(n) -> bool:
    global lista
    for i in lista:
        if n % i == 0: return True
    return False

def main():
    global lista
    n = stdin.readline().strip()
    SALIDA = []
    while len(n) != 0:
        lista =[]
        generate_lucky(int(n))
        SALIDA.append("YES" if is_almost_lucky(int(n)) else "NO")
        n = stdin.readline().strip()
    print("\n".join(SALIDA))
main()