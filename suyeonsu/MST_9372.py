import sys
input = sys.stdin.readline

## 처음엔 이렇게 인접리스트를 탐색하면서 풀었는데
"""
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    graph = {i:[] for i in range(1, n+1)}
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    cnt = 0
    visited = set([1])
    for i, nodes in graph.items():
        cnt += len(set(nodes) - visited)
        visited.update(set(nodes) - visited)
        if len(visited) == n: break
    print(cnt)
"""

## 모든 국가가 연결되어있고 다시 방문해도 상관없으니까 그냥 '국가 수(n)-1'을 출력하면 끝나는 문제였다..
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    for _ in range(m):
        a, b = map(int, input().split())
    print(n-1)
