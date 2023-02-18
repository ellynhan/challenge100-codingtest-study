import sys
input = sys.stdin.readline


def findSquare():
    global cnt
    for i in range(100):
        for j in range(100):
            if graph[i][j] and graph[i][j+1] and graph[i+1][j+1] and graph[i+1][j]:
                cnt += 1
                
def findCurve(x, y, d, g):
    stack = [d]
    graph[x][y] = 1
    x += dx[d]
    y += dy[d]
    graph[x][y] = 1
    for _ in range(1, g+1):
        temp = []
        for i in range(len(stack)-1, -1, -1):
            d = stack[i]
            d = (d+1)%4
            x += dx[d]
            y += dy[d]
            graph[x][y] = 1
            temp.append(d)
        stack += temp
    
n = int(input())

graph = [[0]*101 for _ in range(101)]

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

cnt = 0
for _ in range(n):
    x, y, d, g = map(int, input().split())
    findCurve(x, y, d, g)

findSquare()
print(cnt)
