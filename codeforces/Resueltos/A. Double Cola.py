from sys import stdin

def person(n) -> int:
    
    

def main():
    line = stdin.readline().strip()
    while len(line) != 0:
        n = person(int(line))
        if n == 0:
            print("Sheldon")
        elif n == 1:
            print("Leonard")
        elif n == 2:
            print("Penny")
        elif n == 3:
            print("Rajesh")
        elif n == 4:
            print("Howard")
        line = stdin.readline().strip()

main()
