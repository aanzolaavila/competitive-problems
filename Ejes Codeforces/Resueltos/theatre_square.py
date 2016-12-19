from sys import stdin

def flag(n, m, a):
    x = (n // a) + (1 if n % a != 0 else 0)
    y = (m // a) + (1 if m % a != 0 else 0)
    return x*y

def main():
    linea = stdin.readline().strip()
    while len(linea) != 0:
        n, m, a = [int(c) for c in linea.split()]
        print(flag(n, m, a))
        linea = stdin.readline().strip()
main()
