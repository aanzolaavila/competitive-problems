from sys import stdin

def he_managed(line) -> bool:
    word = "hello"
    for l in line:
        if l != word[0]: continue
        word = word[1:]
        if len(word) == 0: return True
    return False

def main():
    line = stdin.readline().strip()
    SALIDA = []
    while len(line) != 0:
        SALIDA.append("YES" if he_managed(line) else "NO")
        line = stdin.readline().strip()
    print("\n".join(SALIDA))
main()