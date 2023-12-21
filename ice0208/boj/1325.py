import sys
from collections import deque

# PyPy3에서만 정답 처리, Python3에서는 시간 초과

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())

    graph = [[] for _ in range(N + 1)]

    for _ in range(M):
        a, b = map(int, input().split())
        graph[b].append(a)

    max_cnt = 0
    answer = []
    for start in range(1, N + 1):
        q = deque()
        q.append(start)
        cnt = 1
        visit = [False for _ in range(N + 1)]
        visit[start] = True
        while q:
            cur = q.popleft()
            for nxt in graph[cur]:
                if visit[nxt]:
                    continue

                cnt += 1
                visit[nxt] = True
                q.append(nxt)

        if cnt > max_cnt:
            max_cnt = cnt
            answer = [start]
        elif cnt == max_cnt:
            answer.append(start)

    print(*answer)
