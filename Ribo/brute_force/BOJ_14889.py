import sys
input = sys.stdin.readline


def bt(cnt, idx):
    global gap
    if cnt == n//2:
        start, link = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    start += graph[i][j]
                elif not visited[i] and not visited[j]:
                    link += graph[i][j]
        gap = min(gap, abs(start-link))
        return
    
    for i in range(idx, n):
        if not visited[i]:
            visited[i] = True
            bt(cnt+1, i+1)
            visited[i] = False
                    
        
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [False]*n
gap = int(1e9)
bt(0,0)

print(gap)
