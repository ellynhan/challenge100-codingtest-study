import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque

N = int(input())

queue = deque(list(i for i in range(1,N+1)))

while queue:
    if len(queue) > 1:
        x = queue.popleft()
        print(x,end=' ') #카드를 버린다.
        x = queue.popleft()
        queue.append(x) #카드를 맨 밑에다가 넣는다.
    else:
        print(queue.popleft())
        break
    

