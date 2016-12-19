from sys import stdin

def cont(cadena) -> int:
    c, total = 1, 0
    for letra in cadena:
        if letra == "O": c, total = c+1, total + c
        else: c = 1
    return total

def main():
    n = stdin.readline().strip()
    SALIDA = []
    while len(n) != 0:
        SALIDA = [str(cont(stdin.readline().strip())) for i in range(int(n))]
        n = stdin.readline().strip()
    print("\n".join(SALIDA))
main()
