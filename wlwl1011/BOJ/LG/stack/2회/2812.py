import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque

N, K = map(int, input().split())
s = list(map(int, input()))
k = K
queue = deque()
for i in range(N):
  
    while k >0  and queue and queue[-1] < s[i] :
        queue.pop()
        k-=1
    queue.append(s[i])    

for i in range(len(queue)-k):
    print(queue.popleft(),end='')