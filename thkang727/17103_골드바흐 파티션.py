#
#   골드바흐 파티션 실버2
#   17103
#

from sys import stdin


n = int(stdin.readline())
nums=[]

for i in range(n):
    tmp = int(stdin.readline())
    nums.append(tmp)

m = max(nums)
prime_num = [False, False] + [True] *(m) 


for i in range(2,int(m**0.5)+1):
    if prime_num[i]:
        for j in range(i+i, m+1, i):
            if prime_num[j]:
                prime_num[j] = False
for num in nums:
    cnt = 0
    for i in range((num//2)+1):
        if prime_num[i] and prime_num[num-i]:
            cnt +=1
    print(cnt)
    
