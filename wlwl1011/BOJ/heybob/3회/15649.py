import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import permutations

N, M = map(int, input().split())
arr = [i for i in range(1,N+1)]

ans = list(permutations(arr,M))

for i in range(len(ans)):
    print(*ans[i])
