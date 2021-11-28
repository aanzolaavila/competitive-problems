from sys import stdin

def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append(line[0].upper() + line[1:])
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()