import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
line = [tuple(map(int, input().split())) for _ in range(n)]
line.sort()

answer = 0
dq = deque(line)
while len(dq) > 1:
    cur, nxt = dq.popleft(), dq.popleft()
    if cur[1] >= nxt[0]:
        if cur[1] >= nxt[1]:
            dq.appendleft(cur)
        else:
            dq.appendleft((cur[0], nxt[1]))
    else:
        answer += cur[1] - cur[0]
        dq.appendleft(nxt)
answer += dq[-1][1] - dq[-1][0]
print(answer)
