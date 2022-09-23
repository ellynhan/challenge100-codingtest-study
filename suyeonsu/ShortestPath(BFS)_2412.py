from collections import deque
import sys
input = sys.stdin.readline

n, T = map(int, input().split())
p = {tuple(map(int, input().split())):0 for _ in range(n)}

dq = deque([(0, 0, 0)])
p[(0, 0)] = 1
answer = -1
while dq:
    x, y, cnt = dq.popleft()
    if y == T:
        answer = cnt
        break
    for nx in range(x-2, x+3, 1):
        for ny in range(y-2, y+3, 1):
            if nx < 0 or ny < 0: continue
            if (nx, ny) in p and p[(nx, ny)] == 0:
                p[(nx, ny)] = 1
                dq.append((nx, ny, cnt+1))
print(answer)

# 최단경로, 출발지-목적지 키워드 -> bfs를 사용해 풀 수 있음
# nx-x, ny-y가 각각 -2 ~ 2 범위인 모든 경우를 탐색해야하므로 2중 for문을 통해 구현

"""
자료구조마다 in을 사용할 때 시간복잡도가 다르다.

- list, tuple
Average : O(n)
하나하나 순회하기 때문에 O(n)
  
- set, dictionary
Average : O(1), Worst : O(n)
내부적으로 hash를 통해 저장하므로 접근하는 시간은 O(1)
하지만 해쉬의 충돌이 많아 성능이 떨어지는 경우 O(n)이 걸릴 수도 있다.
"""
