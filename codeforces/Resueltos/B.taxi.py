__author__ = 'skinman95'

from sys import stdin
from bisect import bisect_left

def binary_search(a, x, lo=0, hi=None):
    hi = hi if hi is not None else len(a)
    pos = bisect_left(a,x,lo,hi)
    return (pos if pos != hi and a[pos] == x else -1)

def hay_menor(s, n):
    for i in range(n, 0, -1):
        c = binary_search(s, i)
        if c != -1: return c
    return -1

def taxis(s) -> int:
    tax = 0
    while len(s) != 0:
        tax, c = tax +1, s[0]
        del s[0]
        i = hay_menor(s, 4-c)
        while c < 4 and i != -1:
            c += s[i]
            del s[i]
            i = hay_menor(s, 4-c)
    return tax

def main():
    n = stdin.readline().strip()
    while len(n) != 0:
        s = sorted([int(c) for c in stdin.readline().split()])
        print(taxis(s))
        n = stdin.readline().strip()
main()