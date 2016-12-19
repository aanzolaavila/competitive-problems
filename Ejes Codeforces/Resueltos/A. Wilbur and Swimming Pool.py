from sys import stdin

def main():
    case = stdin.readline() # ignorado
    case = stdin.readline().strip()
    cases = []
    while len(case) != 0:
        cases.append(tuple([int(c) for c in case.split()]))
        case = stdin.readline().strip()

,    area = -1
    i, j, terminado = 0, 0, False
    while i < len(cases) and not terminado:
        j = i+1
        while j < len(cases) and not terminado:
            if (cases[i][0] != cases[j][0] and cases[i][1] != cases[j][1]):
                terminado = True
                area = (cases[i][0] - cases[j][0]) * (cases[i][1] - cases[j][1])
                area = area if area >= 0 else -area
            j += 1
        i += 1

    print(area)

main()
