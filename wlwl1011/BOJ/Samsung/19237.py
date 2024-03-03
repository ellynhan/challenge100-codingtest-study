import copy
N, M, K = map(int, input().split())
arr = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def debug():
    # print("제거된 상어리스트: ",remove)
    # print('현재 상어 별 방향 기록', shark_dir)
    # print("현재 상황")
    for x in range(N):
        print(*arr[x])
    # print("현재 냄새")
    # for x in range(N):
    #     for y in range(N):
    #         print(smell[x][y], end=' ')
    #     print()
def isValid(x,y):
    return 0 <= x < N and 0 <= y < N

for _ in range(N):
    arr.append(list(map(int, input().split())))

shark_dir = list(map(int, input().split())) #상어 1번 부터 방향이 기록되어 있습니당.



shark_dir_first = [[] for _ in range(M)] #상어 마리당 방향 우선 순위 입력받음.
idx = 0
cnt = 0
for _ in range(M*4):
    shark_dir_first[idx].append(list(map(int, input().split())))
    cnt += 1
    if cnt == 4:
        idx += 1
        cnt = 0

# for i in range(4):
#     print(*shark_dir_first[i])

def findFirst(number, d, arr):
    # print(number,d, shark_dir_first[number][d])
    for i in range(4):
        if shark_dir_first[number][d][i]-1 in arr:
            return shark_dir_first[number][d][i]-1



#상어는 0 1 2 3
smell = [[[] for _ in range(N)] for _ in range(N)]
remove = []
time = 0
while True:
    time += 1
    if time > 1000:
        print(-1)
        break

    #상어는 냄새를 남긴다
    for x in range(N):
        for y in range(N):
            #smell[x][y] += K #k씩 이동하면 사라지니까.
            #누구의 냄새인지 확인이 필요함. 나중에 이동 시에 필요함.
            if arr[x][y]:
                flag = True
                for i in range(len(smell[x][y])):
                    k, value = smell[x][y][i]
                    if value == arr[x][y]: #이미 흔적을 남기고 간적이 있는 놈
                        smell[x][y][i] = [K,value] #update
                        flag = False
                        break
                if flag: #배열에 없는 값이 었다면.
                    smell[x][y].append((K, arr[x][y]))
    # for x in range(N):
    #     for y in range(N):
    #         print(smell[x][y],end=' ')
    #     print()
    # print("냄새를 남겼습니다.**********")
    # print(time)
    # print(shark_dir)
    # debug()
    #상어는 이동한다.
    new_arr = [[0 for _ in range(N)] for _ in range(N)]
    for x in range(N):
        for y in range(N):
            if arr[x][y]:
                smell_none = []
                smell_me = []

                for i in range(4):
                    tx = x + dx[i]
                    ty = y + dy[i]

                    if isValid(tx,ty):
                        if len(smell[tx][ty]) == 0:
                            smell_none.append(i)

                        else:
                            for k, shark in smell[tx][ty]:
                                if shark == arr[x][y]:
                                    smell_me.append(i)

                # 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
                # print(arr[x][y])
                # print("냄새가 없는 곳으로 가는 방향 배열:",smell_none)
                # print("냄새가 없는 곳이 없을 때 쓰는, 내 냄새가 저장된 배열",smell_me)
                if len(smell_none) == 1:
                    td = smell_none[0]
                    #print('*')

                elif len(smell_none) > 1:
                    td = findFirst(arr[x][y]-1, shark_dir[arr[x][y]-1]-1, smell_none)
                    #print('**')
                # 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다.
                elif len(smell_me) == 1:
                    td = smell_me[0]
                    #print('***')
                else:
                    td = findFirst(arr[x][y] - 1, shark_dir[arr[x][y] - 1]-1, smell_me)
                    #rint('****')
                tx = x + dx[td]
                ty = y + dy[td]
                # print("최종 선택된 방향은 !", td)
                if new_arr[tx][ty]: #이미 누가 차지 하고 있니?
                    # print("****어머나 이미 선택되어있자나"  ,new_arr[tx][ty])

                    if arr[x][y] < new_arr[tx][ty]:
                        remove.append(new_arr[tx][ty])
                        shark_dir[new_arr[tx][ty]-1] = -1 #삭제됨.
                        new_arr[tx][ty] = arr[x][y] #
                        shark_dir[arr[x][y] - 1] = td + 1
                    else:
                        remove.append(arr[x][y])
                        shark_dir[arr[x][y] - 1] = -1  # 삭제됨.
                else:
                    new_arr[tx][ty] = arr[x][y]
                    shark_dir[arr[x][y] - 1] = td+1 #방향을 update
    arr = copy.deepcopy(new_arr)
    # print("상어가 이동했습니다.**********")
    # debug()
    if len(remove) == M-1:
        print(time)
        break
    #냄새 제거하기
    for x in range(N):
        for y in range(N):
            smell_size = len(smell[x][y])
            if smell_size:
                temp = []
                for i in range(smell_size):
                    k, shark_number = smell[x][y][i]
                    k -= 1
                    if k == 0:
                        continue
                    else:
                        temp.append([k, shark_number])
                smell[x][y] = copy.deepcopy(temp)


            #앞선 냄새를 하나씩 줄여야하는데
    # print("냄새 제거하기**********")
    # debug()


