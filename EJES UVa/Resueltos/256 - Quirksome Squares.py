from sys import stdin
import math

def cumple(a, b, n) -> bool:
    return (a + b)**2 == int(str(a).rjust(n, '0') + str(b).rjust(n, '0'))

def calc(n) -> list:
    lista = []
    lim = 10**(n)
    for a in range(lim):
        sq = (4*a*(10**n -1)+1)**0.5
        if type(sq) == complex: continue
        dx = int((4*a-1 + sq)//-2)
        if a+dx >= 0 and cumple(a, a+dx, n): lista.append((a, a+dx))
        dx = int((4*a-1 - sq)//-2)
        if a+dx >= 0 and cumple(a, a+dx, n): lista.append((a, a+dx))

    return lista

def main():
    line = stdin.readline().strip()
    while len(line) != 0:
        n = int(line)
        print( '\n'.join([str(a).rjust(n//2, '0') + str(b).rjust(n//2, '0') for a, b in calc(n//2)]) )
        line = stdin.readline().strip()
main()
