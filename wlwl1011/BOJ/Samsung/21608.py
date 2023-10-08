

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def solve():
    N = int(input())
    like = dict()

    for _ in range(N*N):
        person, a, b, c, d = map(int, input().split())
        like[person] = [a, b, c, d]

    space = [[0 for _ in range(N+1)] for _ in range(N+1)]
    #입력받은 순서대로 .. 자리를 정한다.


    for person, (a, b, c, d) in like.items():
        #비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.

        max_cnt = 0
        max_cnt_list = []
        #각 자리별 빈칸 check
        for x in range(1,N+1):
            for y in range(1,N+1):
                if space[x][y]: #빈칸이 아니면 나가리.
                    continue
                #빈칸 중에서 내가 좋아하는 학생이 많은 칸을 찾아보아여
                cnt = 0
                blank_cnt = 0
                for i in range(4):
                    tx = x+ dx[i]
                    ty = y + dy[i]
                    #내가 좋아하는 학생들!
                    if 1 <= tx <= N and 1 <= ty <= N and (space[tx][ty] == a or space[tx][ty] == b or space[tx][ty] == c or space[tx][ty] == d) :
                        cnt += 1
                    if  1 <= tx <= N and 1 <= ty <= N and not space[tx][ty]:
                        blank_cnt += 1
                if cnt > max_cnt:
                    max_cnt = cnt
                    max_cnt_list = [] #그럼 지금까지 넣었던거 리셋
                    max_cnt_list.append((x, y, person, blank_cnt))
                elif cnt == max_cnt:
                    max_cnt_list.append((x,y,person,blank_cnt))

        #1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
        if len(max_cnt_list) == 1:
            x, y, person,blank_cnt = max_cnt_list[0]
            space[x][y] = person #여기 앉으셈
        else:
            max_cnt_list.sort(key = lambda x : (-x[3],x[0],x[1]))
            x, y, person, blank_cnt = max_cnt_list[0]
            space[x][y] = person


    total_sum = 0
    # 학생의 만족도를 구해야 한다.
    for x in range(1,N+1):
        for y in range(1,N+1):

            cnt = 0
            for i in range(4):
                tx = x + dx[i]
                ty = y + dy[i]

                if 1 <= tx <= N and 1 <= ty <= N:
                    if space[tx][ty] in like[space[x][y]]:
                        cnt += 1

            if cnt == 1:
                total_sum += 1

            elif cnt == 2:
                total_sum += 10

            elif cnt == 3:
                total_sum += 100

            elif cnt == 4:
                total_sum += 1000

    print(total_sum)


solve()

