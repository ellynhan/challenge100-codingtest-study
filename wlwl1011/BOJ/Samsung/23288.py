from collections import deque
dx = [-1,0,1,0]
dy = [0,1,0,-1,0]

dice = [2,1,5,6,4,3]

# 이동 방향은 동쪽
def dice_move(d):

    # print('회전하셈!',d)
    # print('origin:',dice)
    copy_dice = dice[:]

    if d == 0: #북
        dice[0] = copy_dice[1]
        dice[1] = copy_dice[2]
        dice[2] = copy_dice[3]
        dice[3] = copy_dice[0]
        dice[4] = copy_dice[4]
        dice[5] = copy_dice[5]
    elif d == 1:
        dice[0] = copy_dice[0]
        dice[1] = copy_dice[4]
        dice[2] = copy_dice[2]
        dice[3] = copy_dice[5]
        dice[4] = copy_dice[3]
        dice[5] = copy_dice[1]
    elif d == 2: #남
        dice[0] = copy_dice[3]
        dice[1] = copy_dice[0]
        dice[2] = copy_dice[1]
        dice[3] = copy_dice[2]
        dice[4] = copy_dice[4]
        dice[5] = copy_dice[5]
    elif d == 3: #서
        dice[0] = copy_dice[0]
        dice[1] = copy_dice[5]
        dice[2] = copy_dice[2]
        dice[3] = copy_dice[4]
        dice[4] = copy_dice[1]
        dice[5] = copy_dice[3]
    # print('result:', dice)
N, M, K = map(int, input().split())

arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

start_x = 0
start_y = 0
d = 1 #동쪽에서 시작한다.
standard = 0
total_sum = 0

for k in range(K):
    visited = [[0 for _ in range(M)] for _ in range(N)]
    queue = deque()
    tx = start_x + dx[d]
    ty = start_y + dy[d]

    if not (0<= tx < N and 0 <= ty < M):
        tx = start_x + dx[(d+2)%4]
        ty = start_y + dy[(d+2)%4]
        d = (d + 2) % 4
    #print('이동방향:',d)
    start_x = tx
    start_y = ty
    dice_move(d)
    #동쪽으로 한 칸 가서 시작합니다.
    queue.append((start_x,start_y))
    total_sum += arr[start_x][start_y]
    visited[start_x][start_y] = 1
    standard = arr[start_x][start_y]

    while queue:
        #print(queue)
        x, y = queue.popleft()

        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]
            if 0 <= tx < N and 0 <= ty < M:
                if standard == arr[tx][ty]:
                    if not visited[tx][ty]:
                        visited[tx][ty] = 1
                        total_sum += arr[tx][ty]
                        queue.append((tx, ty))

    A = dice[3]
    B = standard
    #print('(A,B):',A,B)
    if A > B: #시계
        d = (d + 1) % 4
    elif A < B:#반시계
        d = (d + 3) % 4


print(total_sum)


