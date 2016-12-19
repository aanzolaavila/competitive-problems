from sys import stdin

def suma(n) -> int:
    s = 1
    for i in range(2, n//2 +1):
        if n % i == 0: s += i
    return s
def main():
    SALIDA = "PERFECTION OUTPUT\n"
    n = int(stdin.readline().strip())
    while n != 0:
        s = suma(n)
        if n == s:
            SALIDA += str(n).rjust(5) + "  PERFECT\n"
        elif n > s:
            SALIDA += str(n).rjust(5) + "  DEFICIENT\n"
        else:
            SALIDA += str(n).rjust(5) + "  ABUNDANT\n"
        n = int(stdin.readline().strip())
    print(SALIDA + "END OF OUTPUT")
main()
