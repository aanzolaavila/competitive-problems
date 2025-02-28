from sys import stdin


def read() -> str:
    return stdin.readline().strip()


def solve(n: int, m: int) -> str:
    actions = []
    k = complex(n, m)

    low, high = (0 + 1j), (1 + 0j)
    found = False
    while not found:
        mid = low + high

        if mid == k:
            found = True
        elif (mid.real / mid.imag) < (k.real / k.imag):
            low = mid
            actions.append("R")
        else:
            high = mid
            actions.append("L")

    return "".join(actions)


def main():
    n, m = [int(i) for i in read().split()]
    while not (n == 1 and m == 1):
        print(solve(n, m))
        n, m = [int(i) for i in read().split()]


main()
