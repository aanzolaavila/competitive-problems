from sys import stdin

def n_stones(stones) -> int:
    n = 0
    for i in range(1, len(stones)):
        if stones[i-1] == stones[i]: n += 1
    return n

def main():
    n = stdin.readline().strip()
    SALIDA = []
    while len(n) != 0:
        SALIDA.append(str(n_stones(stdin.readline().strip())))
        n = stdin.readline().strip()
    print("\n".join(SALIDA))
main()