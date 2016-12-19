from sys import stdin

def tarifa(calls) -> str:
    mile, juice = 0, 0
    for call in calls:
        n = 0
        while not(30*n<=call<= 30*(n+1)-1): n += 1
        mile += 10*(n+1)
        n = 0
        while not(60*n<=call<= 60*(n+1)-1): n += 1
        juice += 15*(n+1)

    if mile == juice:
        return "Mile Juice " + str(mile)
    elif mile < juice:
        return "Mile " + str(mile)
    else: return "Juice " + str(juice)

def main():
    t = int(stdin.readline().strip())
    SALIDA = ""
    for i in range(t):
        c = stdin.readline().strip()
        calls = [int(c) for c in stdin.readline().split()]
        SALIDA += "Case {0}: {1}\n".format(i+1, tarifa(calls))
    print(SALIDA.strip())
main()
        
