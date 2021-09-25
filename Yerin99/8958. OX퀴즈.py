for i in range(int(input())):
    r = input()
    c, g = 0, 0
    for q in r:
        if q == 'O':
            c += 1
            g += c
        else:
            c = 0
    print(g)
