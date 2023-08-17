from collections import deque


# bfs로 7명의 여학생이 붙어있는지 확인한다.
def bfs(arr):
    dr = [-1, +1, 0, 0]  # 상하좌우
    dc = [0, 0, -1, +1]  # 상하좌우

    # 7명 여학생 위치 방문처리를 위한 리스트 1로 처리
    visited = [[1] * 5 for _ in range(5)]

    # 7명의 여학생 위치를 0으로 초기화
    for i in arr:
        visited[i[0]][i[1]] = 0
    # 첫번째 여학생의 위치를 큐에 넣는다.
    queue = deque([(arr[0])])
    # 첫번째 여학생의 방문처리를 1로 변경
    visited[arr[0][0]][arr[0][1]] = 1
    check = 1  # 여학생들의 위치 방문 횟수(첫 위치 방문했기 때문에 1)
    while queue:
        r, c = queue.popleft()  # 큐에 있는 위치 꺼내기

        for i in range(4):  # 델타 위치를 이동하면서
            nr = r + dr[i]
            nc = c + dc[i]
            # 범위를 벗어나면 진행x
            if nr < 0 or nr >= 5 or nc < 0 or nc >= 5:
                continue
            # 만약 위치를 이동하다 아직 여학생 위치를 방문안했다면
            if not visited[nr][nc]:
                visited[nr][nc] = 1  # 그위치를 1로 바꿔주고
                check += 1  # 방문 횟수를 1 증가
                queue.append((nr, nc))  # 큐에 추가
    if check != 7:  # 7번다 방문하지 않았다면
        return False
    else:  # 7번 방문했다면
        return True


def dfs(depth, start, count):
    global result

    if count >= 4:  # 만약 임도연파가 4명이상이라면
        return  # 재귀 탈출

    if depth == 7:  # 7명을 뽑았다면
        if bfs(arr):  # 모든 여학생들이 붙어있다면
            result += 1  # 횟수 1번 추가
        return

    for i in range(start, 25):
        r = i // 5  # 총 25번 중 행은 i 나누기 5와 같다.
        c = i % 5  # 총 25번 중 열은 i를 5로 나눈 나머지와 같다.
        arr.append((r, c))  # 해당 위치를 추가
        dfs(depth + 1, i + 1, count + (students[r][c] == 'Y'))  # 재귀 돈다.
        arr.pop()  # 해당 위치를 제거


students = [list(input()) for _ in range(5)]
arr = []
result = 0
dfs(0, 0, 0)

print(result)