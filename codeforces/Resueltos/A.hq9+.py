from sys import stdin

def output(line) -> bool:
    ins = "".join([c for c in line if c in "HQ9"])
    return len(ins) > 0

def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append("YES" if output(line) else "NO")
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()