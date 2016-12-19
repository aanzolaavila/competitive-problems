from sys import stdin

def min_coins(coins) -> int:
    coins.sort(reverse=True)
    mine, his, actual = 0, sum(coins), 0
    while mine <= his:
        mine, his, actual = mine + coins[actual], his - coins[actual], actual +1
    return actual

def main():
    n = stdin.readline().strip()
    SALIDA = []
    while len(n) != 0:
        coins = [int(c) for c in stdin.readline().split()]
        SALIDA.append(str(min_coins(coins)))
        n = stdin.readline().strip()
    print("\n".join(SALIDA))
main()