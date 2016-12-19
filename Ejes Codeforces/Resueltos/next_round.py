from sys import stdin

def n_part(n, k, a):
    np = 0
    for i in a:
        if i >= a[k-1] and i > 0 : np += 1
    return np

def main():
    linea = stdin.readline().strip()
    while len(linea) != 0:
        n, k = [int(c) for c in linea.split()]
        a = [int(c) for c in stdin.readline().split()]
        print(n_part(n, k, a))
        linea = stdin.readline().strip()
main()
