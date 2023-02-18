import sys
input = sys.stdin.readline


n = int(input())
m = int(input())
brokenButton = list(map(int, input().split()))

minCnt = abs(100-n)
for nums in range(1000001):
    nums = str(nums)
    for i in range(len(nums)):
        if int(nums[i]) in brokenButton:
            break
        
        elif i == len(nums)-1:
            minCnt = min(minCnt, abs(int(nums)-n)+len(nums))

print(minCnt)
