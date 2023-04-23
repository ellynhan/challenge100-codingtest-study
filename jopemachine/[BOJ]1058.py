'''
==============================================================================================
@ Title: 친구
@ URL: https://www.acmicpc.net/problem/1058
@ Author: jopemachine
@ Created Date: 4/16/2023, 12:27:07 PM
@ Tags: bruteforcing floyd_warshall graphs graph_traversal
@ Level: Silver 2
@ Description:
지민이는 세계에서 가장 유명한 사람이 누구인지 궁금해졌다. 가장 유명한 사람을 구하는 방법은 각 사람의 2-친구를 구하면 된다. 어떤
사람 A가 또다른 사람 B의 2-친구가 되기 위해선, 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재해야 된다. 여기서
가장 유명한 사람은 2-친구의 수가 가장 많은 사람이다. 가장 유명한 사람의 2-친구의 수를 출력하는 프로그램을 작성하시오. A와 B가
친구면, B와 A도 친구이고, A와 A는 친구가 아니다.
@ Input: 첫째 줄에 사람의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 각 사람이 친구이면 Y, 아니면
N이 주어진다.
@ Output: 첫째 줄에 가장 유명한 사람의 2-친구의 수를 출력한다.
==============================================================================================
'''

import math


N = int(input())

dist = [[math.inf] * N for _ in range(N)]

for i in range(N):
    s = list(input())
    for j, v in enumerate(s):
        if v == 'Y':
            dist[i][j] = 1

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = -1
for i in range(N):
    cnt = 0
    for j in range(N):
        if i == j:
            continue

        if dist[i][j] <= 2:
            cnt += 1
    ans = max(ans, cnt)

print(ans)
