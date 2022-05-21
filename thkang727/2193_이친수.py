#
#   2193
#   dp 실버3
# #

nums=[1,1,2,3]
last_one = [1,0,1,1]


n = int(input())

for i in range(4,n+1):
    nums.append((nums[i-1]-last_one[i-1])*2+last_one[i-1])
    last_one.append(nums[i-1]-last_one[i-1])
print(nums[n-1])

