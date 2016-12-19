__author__ = 'skinman95'

from sys import stdin

def main():
    n = stdin.readline().strip()
    while len(n) != 0:
        p = 0
        for i in range(int(n)):
            if sum([int(c) for c in stdin.readline().split()]) >= 2:
                p += 1
        print(p)
        n = stdin.readline().strip()
main()