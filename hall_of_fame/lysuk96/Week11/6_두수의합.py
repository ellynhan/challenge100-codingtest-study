n = int(input())
nums = list(map(int, input().split(" ")))
x = int(input())

nums.sort()
print(nums)

lo = 0
hi = n-1
answer=0
while lo < hi:
    target = nums[lo]+nums[hi]
    if target ==x:
        lo+=1
        hi-=1
        answer+=1
    elif target > x:
        hi-=1
    else:
        lo+=1
print(answer)

# answer=0
# for i in range(n-1):
#     for j in range(n-1, i, -1):
#         print(i,j)
#         target = nums[i]+nums[j]
#         if target<x:
#             break
#         elif target==x:
#             answer+=1
#             break
# print(answer)