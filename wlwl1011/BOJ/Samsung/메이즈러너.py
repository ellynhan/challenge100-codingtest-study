from collections import deque
import copy

def distance_check(exit):
    global distance
    global number
    global person

    new_distance = [[0 for _ in range(N)] for _ in range(N)]
    new_number = [[0 for _ in range(N)] for _ in range(N)]
    exit_x, exit_y = exit
    remove = []
    for idx in range(len(person)):
        # 출구까지의 최단거리를 기록한다.
        x, y = person[idx]
        dist = abs(exit_x - x) + abs(exit_y - y)
        if dist:
            new_distance[x][y] = abs(exit_x - x) + abs(exit_y - y)
            new_number[x][y] += 1  # 몇명이 서 있는지 기록한다.
        else:
            remove.append(idx)

    new_person = []
    for idx in range(len(person)):
        if idx in remove:
            continue
        else:
            new_person.append(person[idx])
    person = copy.deepcopy(new_person)

    distance = copy.deepcopy(new_distance)
    number = copy.deepcopy(new_number)


N, M, K = map(int, input().split())
distance = [[0 for _ in range(N)] for _ in range(N)]
number = [[0 for _ in range(N)] for _ in range(N)]
arr = []
for _ in range(N):
    #0이라면, 빈 칸을 의미합니다.
    #1이상 9이하의 값을 갖는다면, 벽을 의미하며, 해당 값은 내구도를 뜻합니다.
    arr.append(list(map(int, input().split())))

person = []
dx = [-1,1,0,0] #우선순위 고려
dy = [0,0,-1,1]

for _ in range(M):
    x,y = map(int, input().split())
    person.append([x-1, y-1])

x, y = map(int, input().split())
exit = (x-1, y-1)

total_sum = 0
for _ in range(K):

    #1초마다 모든 참가자는 한 칸씩 움직입니다. 움직이는 조건은 다음과 같습니다.
    #copy_person = person[:]
    distance_check(exit) #우선 탈출 하는 곳 까지의 거리를 업데이트한다.
    exit_x, exit_y = exit
    remove = []
    # print("참가 자 이동 전")
    # print('exit:',exit)
    # print('person')
    # print(person)
    # print('distance')
    # for i in range(N):
    #     print(*distance[i])
    # print('number')
    # for i in range(N):
    #     print(*number[i])
    # print('arr')
    # for i in range(N):
    #     print(*arr[i])
    for idx in range(len(person)):
        x, y = person[idx]
        flag = False
        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]

            if 0 <= tx < N and 0 <= ty < N:
                if arr[tx][ty]:
                    continue
                dist = abs(exit_x-tx) + abs(exit_y-ty)
                if dist:
                    if distance[x][y] > dist: #작으면 변경가능.
                        total_sum += 1
                        distance[tx][ty] = dist
                        number[tx][ty] += 1
                        number[x][y] -= 1
                        if number[x][y] == 0: #사람이 없으면
                            distance[x][y] = 0
                        person[idx] = [tx,ty] #사람의 위치를 업데이트한다.
                        break
                else:
                    total_sum += 1
                    remove.append(idx)
                    number[x][y] -= 1
                    if number[x][y] == 0:
                        distance[x][y] = 0
    new_person = []
    for idx in range(len(person)):
        if idx in remove:
            continue
        else:
            new_person.append(person[idx])
    person = copy.deepcopy(new_person)

    if not person:
        break

    # print("참가 자 이동 후",total_sum)
    #
    # print('exit:', exit)
    # print('person')
    # print(person)
    # print('distance')
    # for i in range(N):
    #     print(*distance[i])
    # print('number')
    # for i in range(N):
    #     print(*number[i])
    # print('arr')
    # for i in range(N):
    #     print(*arr[i])

    #한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형을 잡습니다.
    copy_arr = copy.deepcopy(arr)
    copy_number = copy.deepcopy(number)
    person_flag = False
    exit_flag = False
    total_flag = False
    new_exit = []
    # print("돌려돌려돌림판 하러 고고!")
    for idx in range(2,N):
        for i in range(0,N):
            for j in range(0,N):

                if not (0 <= i + idx-1 < N and 0 <= j + idx-1 < N):
                    break
                person_flag = False
                exit_flag = False

                for r in range(idx):
                    for c in range(idx):
                        if number[i+r][j+c]: #사람이 있는거임
                            person_flag = True
                        if (i+r,j+c) == exit:
                            exit_flag = True

                if person_flag and exit_flag:
                    total_flag = True

                    for r in range(idx):
                        for c in range(idx):
                            if (i+r,j+c) == exit:
                                # if exit == (0, 1):
                                #     print(i,j)
                                #     print(r,c)
                                #     print(idx)
                                #     print((i+c, j+idx-1-r))
                                new_exit = (i+c, j+idx-1-r)
                                # print('exit result:',exit)
                            number[i+c][j+idx-1-r]= copy_number[i+r][j+c]
                            arr[i+c][j+idx-1-r] = copy_arr[i+r][j+c]
                            if arr[i+c][j+idx-1-r]:
                                arr[i + c][j + idx - 1 - r] -= 1 #내구도 깍임

                    break
            if total_flag:
                break
        if total_flag:
            break
    new_person = []
    for i in range(N):
        for j in range(N):
            for _ in range(number[i][j]):
                new_person.append([i,j])
    person = copy.deepcopy(new_person)
    exit = new_exit[:]
    # print("일단 끝!")
    # print('exit:', exit)
    # print('person')
    # print(person)
    # print('number')
    # for i in range(N):
    #     print(*number[i])

    # print('arr')
    # for i in range(N):
    #     print(*arr[i])
print(total_sum)
print(exit[0]+1, exit[1]+1)