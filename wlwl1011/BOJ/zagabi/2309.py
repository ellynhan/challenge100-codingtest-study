import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import combinations

arr = []

for _ in range(9):
    arr.append(int(input()))

arr.sort()

for a in combinations(arr,7):
    if sum(a) == 100:
        for i in a:
            print(i)
        break
