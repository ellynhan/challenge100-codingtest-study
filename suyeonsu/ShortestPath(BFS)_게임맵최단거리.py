from collections import deque

def solution(maps):
    n, m = len(maps)-1, len(maps[0])-1

    answer = 10000
    dq = deque([(n, m, 1)])
    while dq:
        x, y, cnt = dq.popleft()
        if cnt < answer: 
            if x == 0 and y == 0:
                answer = cnt
            else:
                for dx, dy in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
                    nx, ny = x+dx, y+dy
                    if 0 <= nx <= n and 0 <= ny <= m and maps[nx][ny] == 1:
                        maps[nx][ny] = 0
                        dq.append((nx, ny, cnt+1))
    return answer if answer != 10000 else -1

"""
처음에 DFS로 푸니까 시간초과가 돼서 BFS로 바꾸니까 탐색이 매우 빨랐다.

[DFS의 장/단점]

장점
- 현 경로상의 노드들만 기억하면 되므로 저장공간 수요가 비교적 적다.
- 목표 노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있다.
단점
- 해가 없는 경로가 깊을 경우 탐색시간이 오래 걸릴 수 있다.
- 얻어진 해가 최단 경로가 된다는 보장이 없다.
- 깊이가 무한히 깊어지면 스택오버플로우가 날 위험이 있다. (깊이 제한을 두는 방법으로 해결가능)

[BFS의 장/단점]

장점
- 너비를 우선으로 탐색하므로 답이 되는 경로가 여러 개인 경우에도 최단경로를 반드시 찾을 수 있다.
- 노드 수가 적고 깊이가 얕은 해가 존재할 때 유리하다.
단점
- 큐를 이용하여 다음에 탐색할 노드들을 저장하므로 더 큰 저장공간이 필요하다.
"""
