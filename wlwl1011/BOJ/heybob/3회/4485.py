import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
test_case = 1
while True:
    
    N = int(input())
    if N == 0:
        break
    else:
        arr = []
        
        for _ in range(N):
            arr.append(list(map(int, input().split())))
        queue = deque()
        queue.append((0,0))
        visited = [[int(1e9)] *N for _ in range(N)]
        visited[0][0] = arr[0][0]
        while queue:
            r, c = queue.popleft()

            for i in range(4):
                tr = r + dx[i]
                tc = c + dy[i]

                if 0 <= tr < N and 0<= tc < N:
                    if visited[tr][tc] > visited[r][c] + arr[tr][tc]:
                        visited[tr][tc] =  visited[r][c] + arr[tr][tc]
                        queue.append((tr,tc))
        ans = visited[N-1][N-1] 

        print('Problem ',test_case,': ',ans,sep='')
        test_case += 1    