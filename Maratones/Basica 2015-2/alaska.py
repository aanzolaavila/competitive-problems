from sys import stdin

def posible(lista) -> bool:
    lista.sort()
    pos = 0
    for station in lista:
        if station - pos > 200: return False
        pos = station
    return (1422-pos <= 200) and (1422-pos <= 200 - 1422 + pos)

def main():
    n = int(stdin.readline().strip())
    SALIDA = ""
    while n != 0:
        pos = posible([int(stdin.readline().strip()) for i in range(n)])
        SALIDA += "POSSIBLE\n" if pos else "IMPOSSIBLE\n"
        n = int(stdin.readline().strip())
    print(SALIDA.strip())
main()
