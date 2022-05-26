#
#   10973
#   이전 순열
#   구현 실버3
# #

import sys

input = sys.stdin.readline


n = int(input())
k=-1
arr_n = list(map(int,input().split()))

for i in range(len(arr_n)-1):
    if arr_n[i] > arr_n[i+1]:
        k = i
if k == -1:
    print(-1)
else:
    for i in range(k+1,len(arr_n)):
        if arr_n[i] < arr_n[k]:
            m = i

    arr_n[k], arr_n[m] = arr_n[m], arr_n[k]

    arr_tmp = arr_n[k+1:]
    arr_tmp.sort(reverse=True)
    ans = arr_n[:k+1] + arr_tmp

    for i in range(n):
        print(ans[i], end=" ")
