n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0

def tetroSum(dx, dy):
    global answer
    for x in range(0-min(dx), n-max(dx)):
        for y in range(0-min(dy), m-max(dy)):
            s = 0
            for d in zip(dx, dy):
                nx, ny = x+d[0], y+d[1]
                s += board[nx][ny]
            answer = max(s, answer)

def rotate(dx, dy):
    return dy, [-x for x in dx]

def reflect(dx, dy):
    return dx, [-y for y in dy]

# ㅁ 모양
dx = [0, 0, 1, 1]
dy = [0, 1, 0, 1]
tetroSum(dx, dy)

# ㅡ 모양
dx = [0, 0, 0, 0]
dy = [0, 1, 2, 3]
for _ in range(2):
    tetroSum(dx, dy)
    dx, dy = rotate(dx, dy)

# ㅜ 모양
dx = [0, 0, 0, 1]
dy = [0, 1, 2, 1]
for _ in range(4):
    tetroSum(dx, dy)
    dx, dy = rotate(dx, dy)

# ㄹ 모양
dx = [0, 1, 1, 2]
dy = [0, 0, 1, 1]
for _ in range(2):
    for _ in range(2):
        tetroSum(dx, dy)
        dx, dy = rotate(dx, dy)
    dx, dy = reflect(dx, dy)

# ㄴ 모양
dx = [0, 1, 2, 2]
dy = [0, 0, 0, 1]
for _ in range(2):
    for _ in range(4):
        tetroSum(dx, dy)
        dx, dy = rotate(dx, dy)
    dx, dy = reflect(dx, dy)

print(answer)

# dfs 사용하면 속도가 엄청 빨라진다고 하니 dfs로도 풀어보자
