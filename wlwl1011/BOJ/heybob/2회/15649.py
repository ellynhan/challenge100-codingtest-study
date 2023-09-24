import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from itertools import permutations

N, M = map(int, input().split())
arr = [i for i in range(1,N+1)]

s = list(permutations(arr,M))

s.sort()

for i in range(len(s)):
    print(*s[i])

