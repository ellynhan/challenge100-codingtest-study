import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

game = [0 for _ in range(101)]
# game[1] = 1
ladder = dict()
snake = dict()

dice = [1,2,3,4,5,6]

q = deque()
q.append(1)

for _ in range(n):
    a, b = map(int, input().split())
    ladder[a] = b
    
for _ in range(m):
    a, b = map(int, input().split())
    snake[a] = b
    
while q:
    p = q.popleft()
    
    if p == 100:
        print(game[-1])
        break
    
    for i in dice:
        nextp = p + i
        
        if nextp in ladder:
            nextp = ladder[nextp]
        elif nextp in snake:
            nextp = snake[nextp]
        
        if 0<nextp<101 and game[nextp] == 0:
            game[nextp] = game[p] + 1
            q.append(nextp)
            