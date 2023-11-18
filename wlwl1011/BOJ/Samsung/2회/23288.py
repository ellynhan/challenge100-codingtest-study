from collections import deque

dx = [-1,0,1,0]
dy = [0,1,0,-1]

D = [2,1,5,6,4,3]
def isValid(x,y):
    return 0 <= x < N and 0 <= y < M

def chageDirection(D, d):
    copy_D = D[:]
    if d == 0: #북쪽
        D[0] = copy_D[1]
        D[1] = copy_D[2]
        D[2] = copy_D[3]
        D[3] = copy_D[0]
        D[4] = copy_D[4]
        D[5] = copy_D[5]

    elif d == 1: #동쪽
        D[0] = copy_D[0]
        D[1] = copy_D[4]
        D[2] = copy_D[2]
        D[3] = copy_D[5]
        D[4] = copy_D[3]
        D[5] = copy_D[1]

    elif d == 2: #남쪽
        D[0] = copy_D[3]
        D[1] = copy_D[0]
        D[2] = copy_D[1]
        D[3] = copy_D[2]
        D[4] = copy_D[4]
        D[5] = copy_D[5]

    elif d == 3: #서
        D[0] = copy_D[0]
        D[1] = copy_D[5]
        D[2] = copy_D[2]
        D[3] = copy_D[4]
        D[4] = copy_D[1]
        D[5] = copy_D[3]
    return D


N, M, K = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))


d = 1
x,y = 0,0
total_sum = 0
for _ in range(K):
    tx = x + dx[d]
    ty = y + dy[d]

    if not isValid(tx,ty):
        d = (d + 2) % 4  # 방향 바꾸기
        tx = x + dx[d]
        ty = y + dy[d]
    # print(d)
    D = chageDirection(D, d)
    x,y = tx,ty
    B = arr[x][y]

    queue = deque()
    queue.append((x,y))
    visited = [[0 for _ in range(M)] for _ in range(N)]
    visited[x][y] = 1
    C = 1
    while queue:
        r, c = queue.popleft()

        for i in range(4):
            tr = r + dx[i]
            tc = c + dy[i]

            if isValid(tr,tc):
                if arr[tr][tc] == B and not visited[tr][tc]:

                    visited[tr][tc] = 1
                    C += 1
                    queue.append((tr,tc))

    total_sum += B*C
    A = D[3]
    if A > B:
        d = (d + 1)%4
    elif A < B:
        d = (d + 3) % 4
    # print('result')
    # print(A,B,C)

print(total_sum)