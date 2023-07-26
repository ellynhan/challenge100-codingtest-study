# https://www.acmicpc.net/problem/1744
from collections import deque
N = int(input())

num =[]
for _ in range(N):
    num.append(int(input()))

q = deque(sorted(num))
answer =0
while q:
    if q[0]<=0:
        tmp = q.popleft()
        if q and q[0] <= 0:
            answer+= tmp*q.popleft()
        else:
            answer+=tmp
    elif q[0] == 1:
        answer+=q.popleft()
    else:
        tmp = q.pop()
        if q:
            answer+= tmp*q.pop()
        else:
            answer+=tmp

print(answer)
    
        

