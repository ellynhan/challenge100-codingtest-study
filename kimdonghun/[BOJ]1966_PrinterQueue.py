from collections import deque
import sys

T = int(sys.stdin.readline())

for i in range(T):
    N, M = map(int, sys.stdin.readline().split())
    q = deque(list(map(int, sys.stdin.readline().split())))
    prior_l = deque(list(range(N)))
    cnt = 0

    while q:
        max_num = max(q)
        front = q[0]

        if max_num == front:
            cnt += 1
            q.popleft()
            if prior_l.popleft() == M:
                print(cnt)
                break
        else:
            q.append(q.popleft())
            prior_l.append(prior_l.popleft())
