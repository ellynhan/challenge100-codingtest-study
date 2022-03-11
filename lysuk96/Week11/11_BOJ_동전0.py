N, K = map(int, input().split(" "))
nums = [int(input()) for _ in range(N)]
nums.reverse()

answer = 0
for num in nums:
    answer += K//num
    K %= num

print(answer)
