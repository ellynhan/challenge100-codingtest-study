#
#   2785    체인
#   그리디 실버2
# #

import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int,input().split()))

#print(n//2)

small = arr[0]
small_i = 0
for _ in range(1,len(arr)):
    if arr[_] < small:
        small = arr[_]
        small_i = _
s=0
arr.sort()
for _ in range(0, len(arr)):
    cnt = n - _ - 1
    s += arr[_]
    if s>= cnt:
        print(cnt)
        break

