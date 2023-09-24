n, s = map(int, input().split())
nums = list(map(int, input().split()))
left, right = 0, 0
sum_val = nums[0]
answer = 100001

while True:
    if sum_val >= s:
        sum_val -= nums[left]
        ans = min(answer, right - left + 1)
        left += 1
    else:
        right += 1
        if right == n:
            break
        sum_val += nums[right]

print(0) if answer == 100001 else print(answer)
