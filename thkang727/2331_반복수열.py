#
#   1965
#   dfs/bfs 실버4
# #

import sys

input = sys.stdin.readline

a, p = map(int,input().split())

arr_num = [a]
while True:
    tmp = 0
    for s in str(arr_num[len(arr_num)-1]):
        tmp += int(s) ** p

    if tmp in arr_num:
        break
    arr_num.append(tmp)
    
print(arr_num.index(tmp))
