from sys import stdin

def main():
    linea = stdin.readline().strip()
    while len(linea) != 0:
        w = int(linea)
        if w % 2 == 0 and w != 2: print("YES")
        else: print("NO")
        linea = stdin.readline().strip()
main()
