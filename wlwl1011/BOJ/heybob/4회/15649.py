import sys
from itertools import permutations
input = lambda : sys.stdin.readline().rstrip('\r\n')

N, M = map(int, input().split())
arr = [i for i in range(1,N+1)]

for i in permutations(arr,M):
    print(*i)
