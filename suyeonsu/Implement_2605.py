n = int(input())
order = [0] * n
for stu, i in enumerate(map(int, input().split()), start=1):
    if order[i]: order.insert(i, stu)
    else: order[i] = stu
print(*order[:n][::-1])
