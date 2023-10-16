N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
magics = [tuple(map(int, input().split())) for _ in range(M)]

n2loc = {}  # 번호 -> 좌표
loc2n = {}  # 좌표 -> 번호
n2ball = [-1] * N ** 2  # 번호 -> 번호에 해당하는 공 번호
result = 0


def print_ball():  # 디버그
    for i in range(N):
        print([n2ball[loc2n[(i, j)]] for j in range(N)])
    print()


def init_grid():
    """
    2차원 좌표 정보를 1차원으로 변경
    :return:
    """
    global n2loc, loc2n

    # 우 하 좌 상
    dy_temp = (0, 1, 0, -1)
    dx_temp = (1, 0, -1, 0)

    loc = (0, -1)  # 시작을 (0, -1)로 해서 (0, 0)에서 부터 시작하도록
    cnt = N ** 2 - 1  # 마지막 번호 = N^2-1
    dist, dist_change_flag = N, 1  # 처음 이동거리 N, 이동거리 변화 Flag
    dir = 0

    while True:
        for i in range(dist):
            ny = loc[0] + dy_temp[dir]
            nx = loc[1] + dx_temp[dir]

            loc = (ny, nx)  # 좌표 갱신
            n2loc[cnt] = (ny, nx)  # 번호 -> 좌표
            loc2n[(ny, nx)] = cnt  # 좌표 -> 번호
            n2ball[cnt] = board[ny][nx]  # 번호 -> 구슬 번호
            cnt -= 1

        dir = (dir + 1) % 4  # 방향 번경
        dist_change_flag += 1
        if dist_change_flag == 2:  # 방향을 2번 변경하면 dist 1 감소
            dist_change_flag = 0
            dist -= 1

        if dist == 0: break  # 거리가 0이 되면 종료


def arrangement():
    """
    파괴된 구슬을 정리 (빈 칸에 구슬들을 채움)
    :return:
    """
    global n2ball
    del_cnt = n2ball.count(-1)
    n2ball = [ball for ball in n2ball if ball != -1]  # -1(빈 칸)을 제외하고 다시 n2ball 배열 생성
    n2ball.extend([0] * del_cnt)  # 제외된 칸이 있기 때문에 그만큼 다시 배열을 채워줌


def destroy(d, s):
    """
    방향과 거리에 따라서 구슬들을 파괴함
    :param d: 방향
    :param s: 거리
    :return:
    """
    # 상하좌우
    dy = ("", -1, 1, 0, 0)
    dx = ("", 0, 0, -1, 1)

    shark_loc = (int(N / 2), int(N / 2))  # 상어 좌표
    y, x = shark_loc
    # 거리 상에 존재하는 구슬 모두 파괴
    for i in range(1, s + 1, 1):
        ny = y + dy[d] * i
        nx = x + dx[d] * i

        n = loc2n[(ny, nx)]  # 좌표 -> 번호를 얻음
        n2ball[n] = -1  # 해당 번호의 구슬 값을 -1(빈칸)으로 변경


def destroy2():
    """
    연속하는 구슬 삭제
    :return: 구슬 삭제 여부(True or False)
    """
    global result
    ret = False  # 구슬이 하나도 파괴되지 않은 경우 False 반환

    cnt = 0
    target = 0  # 같은 구슬인지 비교할 대상의 번호
    ball_num = 0  # 해당 번호의 구슬의 숫자

    for i in range(N ** 2):  # 0~N^2-1번 까지 연속하는 구슬인지 조사
        if n2ball[i] == n2ball[target]:  # 연속하는 경우
            cnt += 1  # count += 1
        else:
            # 연속하지 않는 경우
            if cnt >= 4:  # 4개 이상 연속한다면
                ret = True
                for n in range(target, i, 1):  # 해당 번호의 구슬 삭제
                    n2ball[n] = -1
                result += ball_num * cnt  # 점수 추가
            # count, 비교 대상, 번호의 구슬 숫자 초기화
            cnt = 1
            target = i
            ball_num = n2ball[i]

    return ret  # True or False 반환


def translate_all_balls():
    """
    구슬 변화, 연속하는 구슬을 '구슬 개수', '구슬 번호'로 변환하여 n2ball에 추가함
    """
    global n2ball
    new_n2ball = [0]  # 새로운 n2ball, 첫 인덱스에 상어를 의미하는 공백 추가
    group = []  # 연속하는 구슬 저장용 배열
    for n in range(1, N ** 2, 1):
        if not group:
            group.append(n2ball[n])  # group이 []이면 n번째의 구슬 추가
        elif n2ball[n] == group[0]:  # group에 들어있는 구슬 번호가 같은경우
            group.append(n2ball[n])  # 현재 구슬 추가
        else:
            # group에 들어있는 구슬이 다른 경우(연속된 구슬의 종료 시점)
            new_n2ball.append(len(group))  # 구슬의 개수
            new_n2ball.append(group[0])  # 구슬의 번호를 차례대로 추가
            group = [n2ball[n]]  # group을 원소를 현재 구슬로 초기화(뒷 loop 부터는 현재 원소를 기준으로 탐색)

    n2ball = [0] * N ** 2  # n2ball 초기화 후 new_n2ball을 복사함
    for i in range(len(new_n2ball)):
        if i >= (N ** 2): break  # 번호가 넘어가는 경우 break
        n2ball[i] = new_n2ball[i]


def solve():
    # 1. 격자 초기화
    init_grid()
    for d, s in magics:
        # 2. 방향과 거리를 기준으로 구슬 파괴
        destroy(d, s)
        # 3. 파괴된 구슬 정리
        arrangement()
        # 4. 연속하는 구슬 파괴 및 정리
        while True:
            if not destroy2(): break
            arrangement()
        # 5. 구슬 변화
        translate_all_balls()
        # print_ball()


solve()
print(result)