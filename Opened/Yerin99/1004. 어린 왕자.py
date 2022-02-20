def dist(a, b, c, d):
    return ((a-c)**2+(b-d)**2)**0.5


for i in range(int(input())):
    result = 0
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    for j in range(n):
        cx, cy, r = map(int, input().split())
        d1 = dist(cx, cy, x1, y1)
        d2 = dist(cx, cy, x2, y2)
        if (d1-r)*(d2-r) < 0:
            result += 1
    print(result)