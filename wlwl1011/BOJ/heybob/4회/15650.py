import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import combinations

N, M = map(int, input().split())

arr = [i for i in range(1,N+1)]

for i in combinations(arr,M):
    print(*i)

