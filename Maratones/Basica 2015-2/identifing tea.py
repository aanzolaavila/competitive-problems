from sys import stdin

def count(l, n):
    c = 0
    for e in l:
        if e == n: c += 1
    return c

def main():
    n = stdin.readline().strip()
    SALIDA = ""
    while len(n) != 0:
        SALIDA += "\n".join(str(count([int(c) for c in stdin.readline().split()], int(n)))
        n = stdin.readline().strip()
    print(SALIDA)
main()
