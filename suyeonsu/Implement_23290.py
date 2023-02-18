from collections import deque

def moveFish():
    moved = [[[] for _ in range(5)] for _ in range(5)]
    dx = [0, 0, -1, -1, -1, 0, 1, 1, 1]
    dy = [0, -1, -1, 0, 1, 1, 1, 0, -1]
    for x in range(1, 5):
        for y in range(1, 5):
            for direction in origin[x][y]:
                d = direction
                for _ in range(8):
                    nx, ny = x + dx[d], y + dy[d]
                    sm = sum(smell, [])
                    if 1 <= nx <= 4 and 1 <= ny <= 4 and (nx, ny) != (sx, sy) and (nx, ny) not in sm:
                        moved[nx][ny].append(d)
                        break
                    else:
                        d = d - 1 if d > 1 else 8
                else:
                    moved[x][y].append(direction)
    return moved

def product(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in product(arr, r - 1):
                yield [arr[i]] + nxt

def moveShark():
    global sx, sy
    dx = [0, -1, 0, 1, 0]
    dy = [0, 0, -1, 0, 1]

    def getRoute(sx, sy):
        max_val = -1, -1
        for case in list(product([1, 2, 3, 4], 3)):
            cnt = 0
            visited = [[0] * 5 for _ in range(5)]
            x, y = sx, sy
            for direction in case:
                nx, ny = x + dx[direction], y + dy[direction]
                if 1 <= nx <= 4 and 1 <= ny <= 4:
                    if not visited[nx][ny]:
                        visited[nx][ny] = 1
                        cnt += len(board[nx][ny])
                    x, y = nx, ny
                else:
                    break
            else:
                if max_val[0] < cnt:
                    max_val = cnt, case
        return max_val[1]

    smell.append([])
    route = getRoute(sx, sy)
    for direction in route:
        sx += dx[direction]
        sy += dy[direction]
        if 1 <= sx <= 4 and 1 <= sy <= 4 and len(board[sx][sy]):
            board[sx][sy] = []
            smell[-1].append((sx, sy))

def replicateFish():
    for x in range(1, 5):
        for y in range(1, 5):
            for fish in board[x][y]:
                origin[x][y].append(fish)

def countFish():
    cnt = 0
    for row in origin:
        for fish in row:
            cnt += len(fish)
    return cnt

m, s = map(int, input().split())
origin = [[[] for _ in range(5)] for _ in range(5)]
smell = deque()
for _ in range(m):
    fx, fy, d = map(int, input().split())
    origin[fx][fy].append(d)
sx, sy = map(int, input().split())

for practice in range(s):
    board = moveFish()
    moveShark()
    if practice >= 2: smell.popleft()
    replicateFish()
print(countFish())

"""

[조합, 순열, 중복조합, 중복순열 itertools없이 구현하기]

기본 틀은 똑같고, else의 for문에서 재귀호출 할 때 전달하는 리스트가 다른데,

def ___func___(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in ___func___(_____, r-1):
                yield [arr[i]] + nxt

- 조합 (중복 x, 순서 상관 x): combinations(arr[i+1:], r-1)
- 순열 (중복 x, 순서 상관 o): permutations(arr[:i] + arr[i+1:], r-1)
- 중복조합 (중복 o, 순서 상관 x): combinations_with_replacement(arr[i:], r-1)
- 중복순열 (중복 o, 순서 상관 o): product(arr, r-1)

[2차원 리스트 1차원으로 만들기]
sum(arr, [])

"""
