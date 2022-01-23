N = int(input())
nums = [0] + list(map(int, input().split()))
values = [0]
for i in range(1, N+1):
    values.append(0)
    for j in range(0, i):
        if nums[j] < nums[i]:
            values[i] = max(values[i], values[j]+1)
print(max(values))
