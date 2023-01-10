import sys
input = sys.stdin.readline


def check():
    for i in range(1, n+1):
        pos = i
        for now in range(1, h+1):
            if visited[now][pos-1]:
                pos -= 1
            elif visited[now][pos]:
                pos += 1
        if pos != i:
            return False
    return True
    
def bf(cnt, idx):
    global ans
    if cnt > 3:
        return 
    
    if check():
        ans = min(ans, cnt)
        return
        
    for i in range(idx, len(lines)):
        x, y = lines[i]
        if not visited[x][y-1] and not visited[x][y+1]:
            visited[x][y] = True
            bf(cnt+1, i+1)
            visited[x][y] = False
                
                
n, m, h = map(int, input().split())
visited = [[False]*(n+1) for _ in range(h+1)]

for _ in range(m):
    a, b = map(int, input().split())
    visited[a][b] = True

lines = []
for i in range(1, h+1):
    for j in range(1, n):
        if not visited[i][j] and not visited[i][j-1] and not visited[i][j+1]:
            lines.append((i, j))

ans = int(1e9)
bf(0, 0)

if ans < 4:
    print(ans)
else:
    print(-1)
