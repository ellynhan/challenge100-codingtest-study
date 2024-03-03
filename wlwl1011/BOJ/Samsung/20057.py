import copy
N = int(input())
arr= []
for _ in range(N):
    arr.append(list(map(int, input().split())))

dx = [0,1,0,-1] #좌 하 우 상
dy = [-1,0,1,0]

tornado = [[0, 0, 0.02, 0, 0],
          [0, 0.1, 0.07, 0.01, 0],
          [0.05, 0, 0, 0, 0],
          [0, 0.1, 0.07, 0.01, 0],
          [0, 0, 0.02, 0, 0]]

def isValid(x,y):
    return 0 <= x < N and 0 <= y < N
def left90():
    global tornado
    copy_tornado = copy.deepcopy(tornado)
    for i in range(5):
        for j in range(5):
            tornado[5-1-j][i] = copy_tornado[i][j]


def calcurateTornado(x, y, dir):
    global destroy_sand
    relative_x, relative_y = 2, 2
    if arr[x][y] == 0:
        return
    sand = arr[x][y]
    arr[x][y] = 0
    sand_sum = 0
    for i in range(5):
        for j in range(5):
            cal = int(sand * tornado[i][j])
            sand_sum += cal
            if isValid(x - relative_x + i, y - relative_y + j):
                arr[x - relative_x + i][y - relative_y + j] += cal
            else:
                destroy_sand += cal #버려지는 ..

    tx = x + dx[dir]
    ty = y + dy[dir]
    if isValid(tx,ty):
        arr[tx][ty] += sand - sand_sum
    else:
        destroy_sand += sand - sand_sum


x, y = (N-1)//2, (N-1)//2
dist = 1
dir = 0
dist_flag = 0
destroy_sand = 0

# print('start:',x,y)
while True:
    if (x,y) == (0,-1): #끝까지 다 온 거임
        break
    for _ in range(dist): #거리만큼
        tx = x + dx[dir]
        ty = y + dy[dir]
        x = tx
        y = ty
        calcurateTornado(x, y, dir)
    dist_flag += 1
    left90()
    dir = (dir + 1) % 4 #방향은 계속해서 전환이 됩니다.
    if dist_flag == 2: #방향을 전환하자.
        dist += 1
        dist_flag = 0

print(destroy_sand)
