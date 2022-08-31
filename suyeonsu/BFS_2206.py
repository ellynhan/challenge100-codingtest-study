from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().rstrip())) for _ in range(n)]
visited = [[[0, 0] for _ in range(m)] for _ in range(n)]

visited[n-1][m-1][0] = 1
dq = deque([(n-1, m-1, 0)])
while dq:
    x, y, flag = dq.popleft()
    if x == 0 and y == 0:
        print(visited[0][0][flag])
        break
    for dx, dy in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] == 1 and not flag:
                visited[nx][ny][1] = visited[x][y][flag] + 1
                dq.append((nx, ny, 1))
            elif board[nx][ny] == 0 and not visited[nx][ny][flag]:
                visited[nx][ny][flag] = visited[x][y][flag] + 1
                dq.append((nx, ny, flag))
else: print(-1)

# 가능하다면 (n, m) → (1, 1)처럼 거꾸로 올라가도록 구현하자.
# 사실 이 문제에선 문제에 별도의 조건(n, m 쪽에 벽이 있을 가능성이 높다든지하는)은 없었기 때문에 테스트케이스의 차이라고 생각된다.
