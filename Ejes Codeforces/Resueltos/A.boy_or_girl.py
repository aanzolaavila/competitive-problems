from sys import stdin

def is_a_man(line) -> bool:
    letters = []
    for l in line:
        if l not in letters: letters.append(l)
    return len(letters) % 2 != 0


def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append("IGNORE HIM!" if is_a_man(line) else "CHAT WITH HER!")
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()