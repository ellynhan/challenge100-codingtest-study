N = int(input())
nums = list(map(int,input().split()))
dp = -1001
result = -1001
for num in nums:
    dp = max(num, dp+num)
    result = max(result,dp)
print(result)
