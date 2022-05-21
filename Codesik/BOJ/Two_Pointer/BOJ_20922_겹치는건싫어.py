"""
9 2
3 2 5 5 6 4 4 5 7

7


10 1
1 2 3 4 5 6 6 7 8 9

6
"""
N, K = map(int, input().split())
arr = list(input().split())
counter = {}

l, r = 0, 0
ans = -10e9
counter = dict()
while r < N:
    right_count = counter.get(arr[r], 0)
    if right_count < K:
        right_count += 1
        counter[arr[r]] = right_count
        r += 1
    else:
        left_count = counter.get(arr[l], 0)
        left_count -= 1
        counter[arr[l]] = left_count
        l += 1

    ans = max(ans, r-l)
print(ans)




