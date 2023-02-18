a, b = map(int, input().split())
x = int((a**2-b)**.5)
print(-x-a, x-a) if x != -x else print(x-a)
