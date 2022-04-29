#
#   2960
#   구현 실버4
# #

import sys

input = sys.stdin.readline

a, p = map(int,input().split())

check = [False for _ in range(a+1)]
cnt = 0
for i in range(2, a+1):
    if check[i] == False:
        for j in range(i, a+1, i):
            if check[j] == False:
                check[j] = True
                cnt +=1

                if cnt == p:
                    print(j)
                    break

