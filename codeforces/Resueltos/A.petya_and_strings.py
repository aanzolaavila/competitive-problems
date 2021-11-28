from sys import stdin
import string
letters = string.ascii_lowercase

def lex(l1, l2) -> str:
    for i in range(len(l1)):
        if letters.index(l1[i]) < letters.index(l2[i]): return "-1"
        elif letters.index(l1[i]) > letters.index(l2[i]): return "1"
    return "0"

def main():
    line1 = stdin.readline().strip()
    SALIDA = []
    while len(line1) != 0:
        line2 = stdin.readline().strip()
        SALIDA.append(lex(line1.lower(), line2.lower()))
        line1 = stdin.readline().strip()
    print("\n".join(SALIDA))
main()