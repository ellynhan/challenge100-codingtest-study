# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


def solve():
    N, M, K = map(int, input().split())
    #격자크기, 파이어볼 개수, 이동개수

    fire_ball = []
    for _ in range(M):
        #r, c, m, s, d
        fire_ball.append(list(map(int, input().split())))
    count = 0
    while True:
        count += 1
        if count > K:
            break
        #모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
        check_num = dict()
        for i in range(len(fire_ball)):
            r, c, m, s, d = fire_ball[i]
            tr = ((r + dx[d]*s) % N) + 1
            tc = ((c + dy[d]*s) % N) + 1

            r = tr
            c = tc
            if (r, c) in check_num:
                check_num[(r, c)] += 1
            else:
                check_num[(r, c)] = 1
            #이동한것대로 update
            fire_ball[i] = [r, c, m, s, d]

        #이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
        temp = []

        for key, value in check_num.items():
            # print("I will delete")
            # print(key,value)
            # print('Before')
            # for i in range(len(fire_ball)):
            #     print(fire_ball[i])
            if value >= 2:
                # 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
                # 파이어볼은 4개의 파이어볼로 나누어진다.
                total_m = 0 #질량
                total_s = 0 #속력
                total_d = [] #방향

                cnt = 0
                idx = len(fire_ball)-1

                while fire_ball:
                    # print(idx)
                    if idx < 0:
                        break
                    if (fire_ball[idx][0],fire_ball[idx][1]) == (key[0],key[1]):
                        total_m += fire_ball[idx][2]
                        total_s += fire_ball[idx][3]
                        total_d.append(fire_ball[idx][4])
                        fire_ball.pop(idx)
                        cnt += 1

                        if cnt == value:
                            break

                    idx -= 1

                new_m = int(total_m / 5)
                new_s = int(total_s / value)
                check_d = total_d[0]%2

                isAllTrue = True
                for i in range(len(total_d)):
                    if check_d != (total_d[i]%2):
                        isAllTrue = False
                        break
                        # 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                if new_m != 0:
                    if isAllTrue:
                        for i in (0, 2, 4, 6):
                            temp.append(list((key[0],key[1],new_m,new_s,i)))
                    else:
                        for i in (1, 3, 5, 7):
                            temp.append(list((key[0],key[1],new_m,new_s,i)))
            # print('After')
            # for i in range(len(fire_ball)):
            #     print(fire_ball[i])
        for i in temp:
            fire_ball.append(i)

    answer = 0
    for i in range(len(fire_ball)):
        answer += fire_ball[i][2]


    print(answer)



if __name__ == '__main__':
    solve()
