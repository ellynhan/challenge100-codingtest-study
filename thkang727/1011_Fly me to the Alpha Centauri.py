#
#   1011   Fly me to the Alpha Centauri
#   수학 골드5
# #

import sys

input = sys.stdin.readline


t = int(input())

for i in range(t):
    ans,k = 0,1
    move_sum=0
    x, y = input().split()
    x = int(x)
    y = int(y)
    length = y-x

    while(move_sum<length):
        ans+=1
        move_sum+=k
        if ans %2 ==0:
            k+=1
        
    print(ans)
            
