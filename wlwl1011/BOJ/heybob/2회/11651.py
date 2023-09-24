import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N = int(input())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

arr.sort(key=lambda x:(x[1],x[0]))

for i in range(N):
    print(*arr[i])