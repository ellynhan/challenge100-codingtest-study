import sys
from collections import deque

N,K = map(int, sys.stdin.readline().split())

q = deque([i for i in range(1, N+1)])
#print(q)
y_list = []

while(q):
    for i in range(K):
        if i == K-1:
            y_list.append(q[0])
            q.popleft()
        else:
            q.append(q[0])
            q.popleft()

print("<" , end="")
for i in range(len(y_list)):
    if i < len(y_list) - 1:
        print(y_list[i], end=", ")
    else:
        print(y_list[i], end="")
print(">", end="")
