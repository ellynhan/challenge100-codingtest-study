n = int(input())

li = []

for _ in range(n):
    li.append(input())

title = list(set(li))
title.sort()

max = 0

for j in title:
    prev = li.count(j)
    if max < prev:
        max = prev
        ans = j

print(ans)
