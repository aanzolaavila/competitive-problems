__author__ = 'skinman95'

from sys import stdin

def main():
    line = stdin.readline().strip()
    while len(line) != 0:
        m, n = [int(c) for c in line.split()]
        print((m*n)//2)
        line = stdin.readline().strip()
main()