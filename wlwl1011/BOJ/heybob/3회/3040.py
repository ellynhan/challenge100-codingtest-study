import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import combinations

arr = []
for _ in range(9):
    arr.append(int(input()))

diff = sum(arr) - 100
ans = set()
for temp in combinations(arr,2):
    if sum(temp) == diff:
        ans = set(temp)

for i in arr:
    if i in ans:
        continue
    else:
        print(i)        
