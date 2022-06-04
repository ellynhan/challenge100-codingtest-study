#
#   구현 실버4
#  1051 숫자 정사각형
#

from sys import stdin

n, m = map(int, stdin.readline().split())
arr = []
ans = 0
check = min(n,m)

for i in range(n):
    tmp = input()
    arr.append(tmp)
    
for i in range(n):
    for j in range(m):
        for k in range(check):
            if ((i + k) < n) and ((j + k) < m) and(arr[i][j] == arr[i][j + k] == arr[i + k][j] == arr[i + k][j + k]):
                ans = max(ans, (k + 1)**2)

print(ans)
            
