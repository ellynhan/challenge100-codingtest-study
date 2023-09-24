n = int(input())
arr = list(map(int, input().split()))
arr.sort()

l, r = 0, n - 1
cur_sum = abs(arr[l] + arr[r])
result = (arr[l], arr[r])

while l < r:
    sum_val = arr[l] + arr[r]

    if abs(sum_val) < cur_sum:
        cur_sum = abs(sum_val)
        result = (arr[l], arr[r])
        if cur_sum == 0:
            break

    if sum_val < 0:
        l += 1
    else:
        r -= 1

print(result[0], result[1])
