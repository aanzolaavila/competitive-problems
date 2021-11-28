from sys import stdin

def rearrange(line) -> str:
    return "+".join([str(c) for c in sorted([int(i) for i in line.split("+")])])

def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append(rearrange(line))
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()