from sys import stdin

def main():
    n = stdin.readline().strip()
    SALIDA = []
    while len(n) != 0:
        rooms = []
        for i in range(int(n)):
            rooms.append(tuple([int(c) for c in stdin.readline().split()]))
        SALIDA.append(str(sum([1 for c in range(int(n)) if rooms[c][1] - rooms[c][0] >= 2])))
        n = stdin.readline().strip()
    print("\n".join(SALIDA))
main()