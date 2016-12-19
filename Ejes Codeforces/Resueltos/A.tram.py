from sys import stdin

def minimum(data) -> int:
    m, actual = 0, 0
    for d in data:
        actual += d[1] - d[0]
        m = actual if actual > m else m
    return m

def main():
    n = stdin.readline().strip()
    while len(n) != 0:
        data = [tuple([int(c) for c in stdin.readline().split()]) for x in range(int(n))]
        print(minimum(data))
        n = stdin.readline().strip()
main()