
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def isValid(x,y):
    return 0 <= x < N and 0 <= y < N

def debud(number_list):
    for i in range(N):
        for j in range(N):
            if (i,j) == shark:
                print(0, end=' ')
            else:
                print(number_list[arrTon[(i,j)]],end=' ')
        print()

def newNumberList(number_list):
    # 빈칸을 당깁시다.
    new_number_list = []
    for i in range(N ** 2):
        if number_list[i] == -1:
            continue
        new_number_list.append(number_list[i])
    cnt = N ** 2 - len(new_number_list)
    for _ in range(cnt):
        new_number_list.append(0)  # 빈칸을 채워주세요
    return new_number_list

N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

magic = []

for _ in range(M):
    magic.append(list(map(int, input().split())))

#상어좌표
shark = (N//2, N//2)

#좌표가 나선형 얼마에 해당하는지 알아야함!

arrTon = {}

number = N**2 - 1
x, y = 0, -1
check_flag = 1
d = 0#우 하 좌 상 순으로!
dist = N #처음에 N 만큼 진행

tdx = [0,1,0,-1]
tdy = [1,0,-1,0]

while True:
    if number == 0:
        break
    for _ in range(dist):
        tx = x + tdx[d]
        ty = y + tdy[d]
        arrTon[(tx,ty)] = number

        x = tx
        y = ty
        number -= 1
    check_flag += 1
    d = (d + 1) % 4  # 방향 바꾼다.
    if check_flag == 2:
        check_flag = 0
        dist -= 1
# print('*****')
# for key, value in arrTon.items():
#     print('arrTon[',key,']',value)

number_list = [0 for _ in range(N**2)]

for i in range(N):
    for j in range(N):
        if (i,j) == shark:
            continue
        number_list[arrTon[(i,j)]] = arr[i][j]
total_sum = 0

for d, s in magic:
    shark_x, shark_y = shark
    # print("구슬을 파괴시키기 전")
    # debud(number_list)
    #구슬을 파괴 시키자
    for _ in range(s):
        tshark_x = shark_x + dx[d-1]
        tshark_y = shark_y + dy[d-1]
        if isValid(tshark_x,tshark_y):
            value = number_list[arrTon[(tshark_x,tshark_y)]]
            number_list[arrTon[(tshark_x,tshark_y)]] = -1 #파괴
            shark_x = tshark_x
            shark_y = tshark_y

    # print("구슬을 파괴시키기 후")
    # debud(number_list)
    #빈칸을 당깁시다.
    number_list = newNumberList(number_list)
    # print("빈칸을 당깁니다.")
    # debud(number_list)
    #구슬을 폭파시킵니다.

    while True:
        flag = True
        check = number_list[1]
        cnt = 1
        for i in range(2, N**2):
            if check == number_list[i]:
                cnt += 1
            else:
                #그 전에 폭발할게 있었나 확인해봅니다.
                if cnt >= 4:
                    flag = False
                    for j in range(i-cnt,i):
                        number_list[j] = -1
                    total_sum += check * cnt
                check = number_list[i]
                cnt = 1
        if flag:
            break
        number_list = newNumberList(number_list)


    new_number_list = [0]
    check = number_list[1]
    cnt = 1
    for i in range(2, N ** 2):
        if check == number_list[i]:
            cnt += 1
        else:
            #구슬 개수, 구슬 번호.
            if len (new_number_list) < N**2:
                new_number_list.append(cnt)
            if len(new_number_list) < N ** 2:
                new_number_list.append(check)

            check = number_list[i]
            cnt = 1
    cnt = N**2 - len(new_number_list)
    for _ in range(cnt):
        new_number_list.append(0)

    number_list = new_number_list[:]
    # print("구슬을 변화시켰습니다.")
    # debud(number_list)
print(total_sum)