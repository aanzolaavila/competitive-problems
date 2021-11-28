from sys import stdin
import string

upper = string.ascii_uppercase
lower = string.ascii_lowercase
letters = string.ascii_letters

def can_convert(line) -> bool:
    for l in line[1:]:
        if l not in upper: return False
    return line[0] in letters

def convert(line) -> str:
    return (line[0].upper() if line[0] in lower else line[0].lower()) + \
            "".join([line[i].upper() if line[i] not in upper else line[i].lower() for i in range(1,len(line))])

def main():
    line = stdin.readline().strip()
    SALIDA = ""
    while len(line) != 0:
        SALIDA += (convert(line) if can_convert(line) else line) + '\n'
        line = stdin.readline().strip()
    print(SALIDA.strip())
main()
