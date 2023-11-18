
dx = [0, 0, -1, -1, -1, 0, 1, 1, 1]
dy = [0,-1, -1, 0, 1, 1, 1, 0, -1]

N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

move = []
cloud = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]
for _ in range(M):
    move.append(list(map(int, input().split())))


for d,s in move:
    # print('.........')
    #모든 구름이 di 방향으로 si칸 이동한다.

    for i in range(len(cloud)):
        x, y = cloud[i]
        tx = (x + dx[d]*s) % N
        ty = (y + dy[d]*s) % N
        cloud[i] = (tx,ty) #Update
    # print('Move')
    # print(cloud)
    #각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
    magic = []

    for x,y in cloud:
        arr[x][y] += 1
        magic.append((x,y))
    # print('raining')
    # for i in range(N):
    #     print(*arr[i])

    copy_arr = [a[:] for a in arr]
    for x, y in magic:
        for i in (2,4,6,8):#대각선 방향
            tx = x + dx[i]
            ty = y + dy[i]
            if 0<= tx < N and 0 <= ty < N:
                if arr[tx][ty]:
                    copy_arr[x][y] += 1
    arr = copy_arr
    # print('물복사')
    # for i in range(N):
    #     print(*arr[i])
    #바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
    # 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.

    # print('----------')
    # for i in range(N):
    #     print(*arr[i])
    new_cloud = []
    for i in range(N):
        for j in range(N):
            if arr[i][j] >= 2:
                if (i,j) not in cloud:
                    arr[i][j] -= 2
                    new_cloud.append((i, j))
    cloud = new_cloud
    # print('구름생성')
    # print(cloud)
    # print('구름-2')
    # for i in range(N):
    #     print(*arr[i])


    #구름이 모두 사라진다.


total_sum = 0
for i in range(N):
    for j in range(N):
        total_sum += arr[i][j]

print(total_sum)
#마법사 상어는 연습을 위해 1번 행과 N번 행을 연결했고, 1번 열과 N번 열도 연결했다.

#각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.

#구름이 모두 사라진다.