from collections import deque

# 변수 선언 및 입력:
n, m, k = tuple(map(int, input().split()))
# 현재 포탑들이 가진 힘과 언제 각성했는지 기록해줍니다.
board = [
    list(map(int, input().split()))
    for _ in range(n)
]
rec = [
    [0] * m
    for _ in range(n)
]

dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]
dxs2, dys2 = [0, 0, 0, -1, -1, -1, 1, 1, 1], [0, -1, 1, 0, -1, 1, 0, -1, 1]

turn = 0

# 빛의 공격을 할 때 방문 여부와 경로 방향을 기록해줍니다.
vis = [
    [0] * m
    for _ in range(n)
]
back_x = [
    [0] * m
    for _ in range(n)
]
back_y = [
    [0] * m
    for _ in range(n)
]

# 공격과 무관했는지 여부를 저장합니다.
is_active = [
    [False] * m
    for _ in range(n)
]


# 구조체 turret을 정의해 관리합니다.
class Turrent:
    def __init__(self, x, y, r, p):
        self.x = x
        self.y = y
        self.r = r
        self.p = p


# 살아있는 포탑들을 관리합니다.
live_turret = []


# 턴을 진행하기 전 필요한 전처리를 정리해줍니다.
def init():
    global turn
    
    turn += 1
    for i in range(n):
        for j in range(m):
            vis[i][j] = False
            is_active[i][j] = False


# 각성을 진행합니다.
# 각성을 하면 가장 약한 포탑이 n + m만큼 강해집니다.
def awake():
    # 우선순위에 맞게 현재 살아있는 포탑들을 정렬해줍니다.
    live_turret.sort(key=lambda x : (x.p, -x.r, -(x.x + x.y), -x.y))

    # 가장 약한 포탑을 찾아 n + m만큼 더해주고,
    # is_active와 live_turret 배열도 갱신해줍니다.
    weak_turret = live_turret[0]
    x = weak_turret.x
    y = weak_turret.y

    board[x][y] += n + m
    rec[x][y] = turn
    weak_turret.p = board[x][y]
    weak_turret.r = rec[x][y]
    is_active[x][y] = True

    live_turret[0] = weak_turret


# 레이저 공격을 진행합니다.
def laser_attack():
    # 기존에 정렬된 가장 앞선 포탑이
    # 각성한 포탑입니다.
    weak_turret = live_turret[0]
    sx = weak_turret.x
    sy = weak_turret.y
    power = weak_turret.p

    # 기존에 정렬된 가장 뒤 포탑이
    # 각성한 포탑을 제외한 포탑 중 가장 강한 포탑입니다.
    strong_turret = live_turret[-1]
    ex = strong_turret.x
    ey = strong_turret.y

    # bfs를 통해 최단경로를 관리해줍니다.
    q = deque()
    vis[sx][sy] = True
    q.append((sx, sy))

    # 가장 강한 포탑에게 도달 가능한지 여부를 can_attack에 관리해줍니다.
    can_attack = False

    while q:
        x, y = q.popleft()

        # 가장 강한 포탑에게 도달할 수 있다면
        # 바로 멈춥니다.
        if x == ex and y == ey:
            can_attack = True
            break

        # 각각 우, 하, 좌, 상 순서대로 방문하며 방문 가능한 포탑들을 찾고
        # queue에 저장해줍니다.
        for dx, dy in zip(dxs, dys):
            nx = (x + dx + n) % n
            ny = (y + dy + m) % m

            # 이미 방문한 포탑이라면 넘어갑니다.
            if vis[nx][ny]: 
                continue

            # 벽이라면 넘어갑니다.
            if board[nx][ny] == 0: 
                continue

            vis[nx][ny] = True
            back_x[nx][ny] = x
            back_y[nx][ny] = y
            q.append((nx, ny))
    print('길찾기 완료')
    print('back_x')
    for i in range(len(back_x)):
        print(*back_x[i])
    print('back_y')   
    for i in range(len(back_y)):
        print(*back_y[i]) 
    # 만약 도달 가능하다면 공격을 진행합니다.
    if can_attack:
        # 우선 가장 강한 포탑에게는 power만큼의 공격을 진행합니다.
        board[ex][ey] -= power
        if board[ex][ey] < 0: 
            board[ex][ey] = 0
        is_active[ex][ey] = True

        # 기존의 경로를 역추적하며
        # 경로 상에 있는 모든 포탑에게 power // 2만큼의 공격을 진행합니다.
        cx = back_x[ex][ey]
        cy = back_y[ex][ey]

        while not (cx == sx and cy == sy):
            board[cx][cy] -= power // 2
            if board[cx][cy] < 0: 
                board[cx][cy] = 0
            is_active[cx][cy] = True

            next_cx = back_x[cx][cy]
            next_cy = back_y[cx][cy]

            cx = next_cx
            cy = next_cy

    # 공격을 성공했는지 여부를 반환합니다.
    return can_attack


# 레이저 공격을 하지 못했다면 폭탄 공격을 진행합니다.
def bomb_attack():
    # 기존에 정렬된 가장 앞선 포탑이
    # 각성한 포탑입니다.
    weak_turret = live_turret[0]
    sx = weak_turret.x
    sy = weak_turret.y
    power = weak_turret.p

    # 기존에 정렬된 가장 뒤 포탑이
    # 각성한 포탑을 제외한 포탑 중 가장 강한 포탑입니다.
    strong_turret = live_turret[-1]
    ex = strong_turret.x
    ey = strong_turret.y

    # 가장 강한 포탑의 3 * 3 범위를 모두 탐색하며
    # 각각에 맞는 공격을 진행합니다.
    for dx2, dy2 in zip(dxs2, dys2):
        nx = (ex + dx2 + n) % n
        ny = (ey + dy2 + m) % m

        # 각성한 포탑 자기 자신일 경우 넘어갑니다.
        if nx == sx and ny == sy: 
            continue

        # 가장 강한 포탑일 경우 pow만큼의 공격을 진행합니다.
        if nx == ex and ny == ey:
            board[nx][ny] -= power
            if board[nx][ny] < 0: 
                board[nx][ny] = 0
            is_active[nx][ny] = True
        # 그 외의 경우 pow // 2만큼의 공격을 진행합니다.
        else:
            board[nx][ny] -= power // 2
            if board[nx][ny] < 0: 
                board[nx][ny] = 0
            is_active[nx][ny] = True


# 공격에 관여하지 않은 모든 살아있는 포탑의 힘을 1 증가시킵니다.
def reserve():
    for i in range(n):
        for j in range(m):
            if is_active[i][j]: 
                continue
            if board[i][j] == 0: 
                continue
            board[i][j] += 1


# k턴 동안 진행됩니다.
for _ in range(k):
    # 턴을 진행하기 전 살아있는 포탑을 정리합니다.
    live_turret = []
    for i in range(n):
        for j in range(m):
            if board[i][j]:
                new_turret = Turrent(i, j, rec[i][j], board[i][j])
                live_turret.append(new_turret)

    # 살아있는 포탑이 1개 이하라면 바로 종료합니다.
    if len(live_turret) <= 1: 
        break

    # 턴을 진행하기 전 필요한 전처리를 정리해줍니다.
    init()

    # 각성을 진행합니다.
    awake()

    # 레이저 공격을 진행합니다.
    is_suc = laser_attack()
    # 레이저 공격을 하지 못했다면 포탄 공격을 진행합니다.
    if not is_suc: 
        bomb_attack()

    # 공격에 관여하지 않은 모든 살아있는 포탑의 힘을 1 증가시킵니다.
    reserve()

# 살아있는 포탑의 힘 중 가장 큰 값을 출력합니다.
ans = 0
for i in range(n):
    for j in range(m):
        ans = max(ans, board[i][j])

print(ans)