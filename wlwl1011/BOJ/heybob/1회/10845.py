import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque
N = int(input())
queue = deque()

for _ in range(N):
    command = input().split()
    
    if command[0] == 'push':
        queue.append(int(command[1]))
    elif command[0] == 'pop':
        if queue:
            print(queue.popleft())
        else:
            print(-1)    
    elif command[0] == 'size':
        print(len(queue))
    elif command[0] == 'empty':
        if queue:
            print(0)
        else:       
            print(1)
    elif command[0] == 'front' :
        if queue:
            print(queue[0])
        else:
            print(-1)
    elif command[0] == 'back':
        if queue:
            print(queue[-1])
        else:
            print(-1)                                
