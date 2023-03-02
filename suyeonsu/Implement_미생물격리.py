"""
n*n board에 k개의 미생물 군집이 있다.
각 군집은 (x, y, cnt, d)의 정보로 이루어져 있다.
m시간 후 남아있는 미생물수의 총합을 구하라

1~m번 동안
    주어진 k개의 군집들을 방향에 맞춰 1칸씩 이동시킨다.
    각 군집들의 다음 이동방향을 저장함
    -> 딕셔너리에 (nx, ny) : [군집들]로 저장
    만약 해당 좌표에 대해 여러 군집이 있다면
        -> 미생물이 가장 많은 군집에 미생물수 총합을 저장, dict[(nx, ny)]에서 나머지 군집 삭제
    해당 좌표(nx, ny)로 각 군집을 이동시킨다.
    만약 nx == 0 or ny == 0 or nx == n or ny == n이라면 약품이 칠해진 셀이므로
        해당 군집 정보에서 방향을 반대로 바꿔서 저장함
        미생물수 /= 2
"""
dir = {1:(-1, 0), 2:(1, 0), 3:(0, -1), 4:(0, 1)}

T = int(input())
for t in range(1, T+1):
    n, m, k = map(int, input().split())
    info = [list(map(int, input().split())) for _ in range(k)]
    idx = set(range(k))
    for _ in range(m):
        nxt = {}
        for i, (x, y, cnt, d) in enumerate(info):
            nx, ny = x+dir[d][0], y+dir[d][1]
            if 0 <= nx < n and 0 <= ny < n:
                if (nx, ny) not in nxt.keys(): nxt[(nx, ny)] = []
                nxt[(nx, ny)].append(i)
        for (nx, ny), lst in nxt.items():
            if len(lst) > 1:
                max_i = lst[0]
                for i in lst[1:]:
                    if info[max_i][2] < info[i][2]:
                        max_i = i
                cnt = info[max_i][2]
                for i in lst:
                    if i != max_i:
                        cnt += info[i][2]
                info[max_i][2] = cnt
                nxt[(nx, ny)] = max_i
            else:
                nxt[(nx, ny)] = lst[0]
        for (nx, ny), i in nxt.items():
            if nx in [0, n-1] or ny in [0, n-1]:
                nd = 0
                if info[i][3] == 1: nd = 2
                elif info[i][3] == 2: nd = 1
                elif info[i][3] == 3: nd = 4
                else: nd = 3
                info[i] = [nx, ny, info[i][2]//2, nd]
            else:
                info[i][0], info[i][1] = nx, ny
        tmp = []
        for i in nxt.values():
            tmp.append(info[i])
        info = tmp
    answer = 0
    for x, y, cnt, d in info:
        answer += cnt
    print(f'#{t} {answer}')
