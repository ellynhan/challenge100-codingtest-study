import collections


def bfs(cur_r, cur_c, dst_r, dst_c):
    q = collections.deque()
    q.append([cur_r, cur_c, -1])
    V[cur_r][cur_c] = 1
    while q:
        cur_r, cur_c, cnt = q.popleft()
        if cur_r == dst_r and cur_c == dst_c:
            return cnt
        for dx, dy in dr:
            nxt_r, nxt_c = cur_r, cur_c
            while True:
                nxt_r, nxt_c = nxt_r + dx, nxt_c + dy
                if 0 <= nxt_r <= H - 1 and 0 <= nxt_c <= W - 1:
                    if A[nxt_r][nxt_c] == '*':
                        break
                    if not V[nxt_r][nxt_c]:
                        q.append([nxt_r, nxt_c, cnt + 1])
                        V[nxt_r][nxt_c] = 1
                else:
                    break


W, H = map(int, input().split())
A = [list(input()) for _ in range(H)]
V = [[0] * W for _ in range(H)]
dr = [[0, -1], [0, 1], [-1, 0], [1, 0]]
conn_points = []
for r in range(H):
    for c in range(W):
        if A[r][c] == 'C':
            conn_points.append([r, c])
start_r, start_c = conn_points[0][0], conn_points[0][1]
dst_r, dst_c = conn_points[1][0], conn_points[1][1]
print(bfs(start_r, start_c, dst_r, dst_c))