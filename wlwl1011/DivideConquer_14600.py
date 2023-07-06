import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input()) 
i, j = map(int, input().split())

arr = [ [0 for _ in range(2**N)] for _ in range(2**N) ]
i -=1 
j -=1

arr[i][j] = -1

num = 1

def dfs(r, c, k, area):
    global num
    n = n // 2
    
    if k <= 1:
        cnt = 3
        if area == 0 or area == 4: 
            for i in range(r, r+2)

dfs(0, 0, N, num)