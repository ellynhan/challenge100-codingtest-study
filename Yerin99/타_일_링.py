data = list(map(int, input().split()))
ans = [0]*(max(data)+1)

for x in data:
    for j in range(x):
        ans[j] += 1

print(*ans, end=" ")
