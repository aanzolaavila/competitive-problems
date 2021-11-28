from sys import stdin

def value(ops) -> int:
    v = 0
    for o in ops:
        for i in o.split('X'):
            if i == "++":
                v += 1
            elif i == "--":
                v -= 1
    return v

def main():
    n = stdin.readline().strip()
    while len(n) != 0:
        ops = [stdin.readline().strip() for c in range(int(n))]
        print(value(ops))
        n = stdin.readline().strip()
main()