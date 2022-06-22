#
#   11501 주식
#   그리디 실버2
# #

import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    n = int(input())
    arr = list(map(int,sys.stdin.readline().rstrip("\n").split()))
    ans, max = 0, 0
    
    for j in range(len(arr)-1,-1,-1):
        if(arr[j] > max):
            max = arr[j]
        else:
            ans += max - arr[j]
    print(ans)
