from collections import deque
N, Q = map(int, input().split())
arr = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]

for _ in range(2**N):
    arr.append(list(map(int, input().split())))

L = list(map(int, input().split()))

for l in L:
    #print('----------')
    l_size = 2**l
    #print(l_size)
    copy_arr = [a[:] for a in arr]
    for x in range(0, 2**N, l_size):
        for y in range(0, 2**N, l_size):
            for i in range(l_size):
                for j in range(l_size):
                    arr[x+j][y+l_size-i-1] = copy_arr[x+i][y+j]
    # print('회전합니다.')
    # for x in range(2**N):
    #     print(*arr[x])
    #이후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
    copy_arr = [a[:] for a in arr]
    for x in range(2**N):
        for y in range(2**N):
            if copy_arr[x][y] == 0:
                continue
            cnt = 0
            for i in range(4):
                tx = x + dx[i]
                ty = y + dy[i]
                if 0 <= tx < 2**N and 0 <= ty < 2**N:
                    if copy_arr[tx][ty]:
                        cnt += 1
            if cnt < 3:
                arr[x][y] -= 1
    # print('줄어듭니다.')
    # for x in range(2 ** N):
    #     print(*arr[x])
#남아있는 얼음 A[r][c]의 합
total_sum = 0
for x in range(2 ** N):
    for y in range(2 ** N):
        total_sum += arr[x][y]

#남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
max_ice = 0
for x in range(2 ** N):
    for y in range(2 ** N):

        if arr[x][y] == 0:
            continue
        queue = deque()
        queue.append((x,y))
        visited = [[0 for _ in range(2**N)] for _ in range(2**N)]
        cnt = 1
        visited[x][y] = 1
        while queue:
            r, c = queue.popleft()

            for i in range(4):
                tr = r + dx[i]
                tc = c + dy[i]

                if 0 <= tr < 2**N and 0 <= tc < 2**N:
                    if not visited[tr][tc] and arr[tr][tc] > 0:
                        queue.append((tr,tc))
                        visited[tr][tc] = 1
                        cnt += 1
        max_ice = max(max_ice, cnt)
print(total_sum)
print(max_ice)

