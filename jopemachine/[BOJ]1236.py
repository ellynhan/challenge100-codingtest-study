'''
==============================================================================================
@ Title: 성 지키기
@ URL: https://www.acmicpc.net/problem/1236
@ Author: jopemachine
@ Created Date: 12/11/2022, 3:23:11 PM
@ Tags: implementation
@ Level: Bronze 1
@ Description:
영식이는 직사각형 모양의 성을 가지고 있다. 성의 1층은 몇 명의 경비원에 의해서 보호되고 있다. 영식이는 모든 행과 모든 열에 한 명
이상의 경비원이 있으면 좋겠다고 생각했다. 성의 크기와 경비원이 어디있는지 주어졌을 때, 몇 명의 경비원을 최소로 추가해야 영식이를
만족시키는지 구하는 프로그램을 작성하시오.
@ Input: 첫째 줄에 성의 세로 크기 N과 가로 크기 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 성의
상태가 주어진다. 성의 상태는 .은 빈칸, X는 경비원이 있는 칸이다.
@ Output: 첫째 줄에 추가해야 하는 경비원의 최솟값을 출력한다.
==============================================================================================
'''

N, M = map(int, input().split())

_map = []
for _ in range(N):
    _map.append(list(input()))

ans = 0
for i in range(N):
    for j in range(M):
        if _map[i][j] == 'X':
            continue

        should_put = True
        for r in range(N):
            if _map[r][j] == 'X':
                should_put = False
                break

        if should_put:
            for c in range(M):
                if _map[i][c] == 'X':
                    should_put = False
                    break

        if should_put:
            _map[i][j] = 'X'
            ans += 1

for i in range(N):
    is_empty_row = True
    for j in range(M):
        if _map[i][j] == 'X':
            is_empty_row = False
            break

    if is_empty_row:
        ans += 1

for i in range(M):
    is_empty_col = True
    for j in range(N):
        if _map[j][i] == 'X':
            is_empty_col = False
            break

    if is_empty_col:
        ans += 1

print(ans)
