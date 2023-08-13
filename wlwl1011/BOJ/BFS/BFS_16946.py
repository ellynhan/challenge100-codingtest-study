
from collections import deque

# 현 위치에서 방문할 수 있는 개수를 세는 함수
def bfs(start_x, start_y):
    q = deque()
    q.append((start_x, start_y))
    # 시작 위치 방문 표시
    visited[start_x][start_y] = 1
    # 시작 위치 개수 세기
    cnt = 1
    # 큐가 빌 때까지
    while q:
        x, y = q.popleft()
        # 현재 그룹에 포함
        zeros[x][y] = group
        # 4가지 이동 방향에 대하여
        for i in range(4):
            # 이동 위치 확인
            nx, ny = x + dx[i], y + dy[i]
            # 이동할 위치가 맵을 벗어나면 건너뛰기
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            # 이미 방문한 위치라면 건너뛰기
            if visited[nx][ny]:
                continue
            # 이동할 위치가 빈 곳이라면
            if not graph[nx][ny]:
                # 큐에 추가
                q.append((nx, ny))
                # 방문 표시
                visited[nx][ny] = 1
                # 개수 세기
                cnt += 1
    return cnt

# 이동할 수 있는 총 그룹의 개수를 세는 함수
def move_count(x, y):
    # 그룹 번호를 담기 위한 집합 데이터 생성
    data = set()
    # 4가지 방향에 대하여
    for i in range(4):
        # 이동 위치 확인
        nx, ny = x + dx[i], y + dy[i]
        # 맵을 벗어나면 건너뛰기
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        # 그룹에 속해 있지 않는 위치 건너뛰기
        if not zeros[nx][ny]:
            continue
        # 현재 그룹에 포함된 개수를 집합 데이터에 추가
        data.add(zeros[nx][ny])
    # 현재 x, y 위치 세기
    cnt = 1
    # 갈 수 있는 모든 그룹에 대하여 한 그룹씩 받으면서
    for c in data:
        # 딕셔너리에 추가
        cnt += info[c]
        # 이동할 수 있는 칸의 개수를 10으로 나눈 나머지 계산
        cnt %= 10
    # 출력값 반환
    return cnt

# 문제에서 주어진 데이터 입력받기
n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]

# 방문 표시 확인 2차원 배열
visited = [[0] * m for _ in range(n)]
# 그룹 번호를 알려주는 2차원 배열
zeros = [[0] * m for _ in range(n)]
# 출력값을 나타내는 2차원 배열
answer = [[0] * m for _ in range(n)]

# 1번 그룹 생성
group = 1
# (그룹명, 그룹 안에 포함된 총 개수) 딕셔너리 생성
info = {}

# 상, 하, 좌, 우 위치 확인
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
# 전체 데이터를 하나씩 살펴보며
for i in range(n):
    for j in range(m):
        # 이동할 수 있거나 아직 방문하지 않은 위치라면
        if not graph[i][j] and not visited[i][j]:
            # 현재 위치에서 이동할 수 있는 0의 개수 세기
            cnt = bfs(i, j)
            # 딕셔너리에 그룹명과 개수 추가
            info[group] = cnt
            # 다음 그룹
            group += 1
# 전체 데이터를 하나씩 살펴보며
for i in range(n):
    for j in range(m):
        # 벽이 있다면
        if graph[i][j]:
            # 벽을 부수고 인접해 있는 그룹의 총 개수 받기
            answer[i][j] = move_count(i, j)
# 정답 출력
for i in range(n):
    print("".join(map(str, answer[i])))