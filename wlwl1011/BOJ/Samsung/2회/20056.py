import copy
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

N, M, K = map(int, input().split()) #크기, 파이어볼 개수, K번 이동 명령

fireball = {}

for _ in range(M):
    r, c, m, s, d = map(int, input().split())
    fireball[(r-1,c-1)] = [[m, s, d]]

for _ in range(K): #K번의 이동 명령
    # print('------')
    #모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다
    new_fireball = {}
    # print('Before')

    # for key, value in fireball.items():
    #     print(key, value)
    for  (r, c), value  in fireball.items():
        for m,s,d in fireball[(r,c)]:
            tr = (r + dx[d]*s) % N
            tc = (c + dy[d]*s) % N
            if (tr,tc) in new_fireball:
                new_fireball[(tr, tc)].append([m, s, d])
            else:
                new_fireball[(tr, tc)] = [[m, s, d]]
    fireball = copy.deepcopy(new_fireball)
    # print('1')
    # for (r, c), value in fireball.items():
    #     print((r, c), value)
    new_fireball = {}
    remove = []
    for (r, c), value in fireball.items():
        if len(fireball[(r,c)]) >= 2:
          #같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
            size = len(fireball[(r,c)])
            mm = 0
            ss = 0
            dd = []

            for [m, s, d] in fireball[(r,c)]:
                mm += m
                ss += s
                dd.append(d)
            #del fireball[(r, c)]  #초기화
            remove.append((r, c))
            check = dd[0] % 2 #홀수든 짝수든
            flag = True

            for i in range(size):
                if check != dd[i] % 2:
                    flag = False
                    break
            # print('방향을 정해주자')
            # print(dd)
            # print(flag)
            if flag:
                for i in (0, 2, 4, 6):  #4개의 파이어볼로 나누어진다.
                    if (r,c) in new_fireball:
                        new_fireball[(r, c)].append([int(mm/5), int(ss/size), i])
                    else:
                        new_fireball[(r, c)] = [[int(mm/5), int(ss/size), i]]
            else:
                for i in (1, 3, 5, 7):  # 4개의 파이어볼로 나누어진다.
                    if (r, c) in new_fireball:
                        new_fireball[(r, c)].append([int(mm/5), int(ss/size), i])
                    else:
                        new_fireball[(r, c)] = [[int(mm/5), int(ss/size), i]]
    for (r,c) in remove:
        del fireball[(r, c)]

    for (r,c), value in new_fireball.items():
        for [m,s,d] in new_fireball[(r,c)]:
            if (r, c) in fireball:
                fireball[(r, c)].append([m, s, d])
            else:
                fireball[(r, c)] = [[m, s, d]]

    new_fireball = {}
    for (r, c), value in fireball.items():
        for (m, s, d) in fireball[(r,c)]:
            if m == 0:
                continue
            else:
                if (r, c) in new_fireball:
                    new_fireball[(r,c)].append([m, s, d])
                else:
                    new_fireball[(r, c)] = [[m , s ,d]]
    fireball = copy.deepcopy(new_fireball)

    # print('2')
    # for key, value in fireball.items():
    #     print(key, value)
total_sum = 0
for (r, c), value in fireball.items():
    #print(fireball[(r,c)])
    for [m, s, d] in fireball[(r, c)]:
        total_sum += m


print(total_sum)


