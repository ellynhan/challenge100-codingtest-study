def han(n):
    c = 0
    for i in range(100, n+1):
        i = str(i)
        if int(i[1]) * 2 == int(i[0]) + int(i[2]):
            c += 1
    return c


x = int(input())
if x // 100 == 0:
    print(x)
else:
    print(99 + han(x))
