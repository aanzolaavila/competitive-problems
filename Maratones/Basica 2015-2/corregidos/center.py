from sys import stdin

def main():
    n, m = [stdin.readline().split()]
    while n != 0 and m != 0:
        data = [stdin.readline().strip() for i in range(m)]
        u, d = [int(c) for c in data.split()]
        if u > d:
            
            
            
