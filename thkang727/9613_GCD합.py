#
#   9613   GCD 합
#   수학   실버3
# #

import sys
import math

input = sys.stdin.readline

t = int(input())

arr = []
for i in range(t):
    arr = list(input().split())
    ans=0
    for j in range(1,len(arr)):
        
        tmp = int(arr[j])
        #print(tmp)
        for k in range(j+1,len(arr)):
            ttmp = int(arr[k])
            ans += math.gcd(tmp, ttmp)
            #print(math.gcd(tmp,ttmp))
    print(ans)

