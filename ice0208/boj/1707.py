import sys
from collections import deque

input = sys.stdin.readline


def solution(V, E, graph):
    visit = [0 for v in range(V + 1)]

    for i in range(1, V + 1):
        if visit[i] != 0:
            continue

        q = deque()
        q.append(i)
        visit[i] = 1

        while q:
            cur = q.popleft()
            for nxt in graph[cur]:
                if visit[nxt] != 0:
                    if visit[cur] == visit[nxt]:
                        return "NO"
                    continue

                visit[nxt] = 1 if visit[cur] == -1 else -1
                q.append(nxt)

    return "YES"


if __name__ == "__main__":
    T = int(input())

    answers = []

    for t in range(T):
        V, E = map(int, input().split())

        graph = [[] for v in range(V + 1)]

        for e in range(E):
            a, b = map(int, input().split())
            graph[a].append(b)
            graph[b].append(a)

        answer = solution(V, E, graph)
        answers.append(answer)

    for answer in answers:
        print(answer)
