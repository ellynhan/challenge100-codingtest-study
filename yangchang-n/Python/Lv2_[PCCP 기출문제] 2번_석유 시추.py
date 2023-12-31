from queue import deque

def bfs(x, y, land, n, m, visited, result) :
    check_deque = deque([(x, y)])
    visited[x][y] = True
    count = 0
    record_col = []

    while check_deque :
        cx, cy = check_deque.popleft()
        if not cy in record_col :
            record_col.append(cy)
        count += 1

        for (dx, dy) in [(1, 0), (0, 1), (-1, 0), (0, -1)] :
            nx, ny = cx + dx, cy + dy
            if (0 <= nx < n) and (0 <= ny < m) :
                if not visited[nx][ny] and land[nx][ny] :
                    check_deque.append((nx, ny))
                    visited[nx][ny] = True

    for i in range(len(record_col)) :
        result[record_col[i]] += count

def solution(land) :
    n, m = len(land), len(land[0])
    visited = [[False] * m for _ in range(n)]
    result = [0] * m

    for i in range(n) :
        for j in range(m) :
            if not visited[i][j] and land[i][j] :
                bfs(i, j, land, n, m, visited, result)

    answer = max(result)

    return answer
