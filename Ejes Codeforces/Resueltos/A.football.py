from sys import stdin

def is_dangerous(line) -> bool:
    actual, cont = line[0], 1
    for i in range(1, len(line)):
        if line[i] == actual: cont += 1
        else: actual, cont = line[i], 1
        if cont >= 7: return True
    return False

def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append("YES" if is_dangerous(line) else "NO")
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()