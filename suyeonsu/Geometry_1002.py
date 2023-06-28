for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1-x2)**2 + (y1-y2)**2)**.5
    if d == 0 and r1 == r2: print(-1)
    elif r1+r2 == d or abs(r1-r2)==d: print(1)
    elif abs(r1-r2) < d < r1+r2: print(2)
    else: print(0)
