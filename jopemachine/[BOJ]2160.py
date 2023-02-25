'''
==============================================================================================
@ Title: 그림 비교
@ URL: https://www.acmicpc.net/problem/2160
@ Author: jopemachine
@ Created Date: 12/7/2022, 8:49:22 PM
@ Tags: bruteforcing implementation
@ Level: Bronze 1
@ Description:
N(2 ≤ N ≤ 50)개의 그림이 있다. 각각의 그림은 5×7의 크기이고, 두 가지 색으로 되어 있다. 이때 두 가지의 색을 각각
‘X’와 ‘.’으로 표현하기로 하자. 이러한 그림들이 주어졌을 때, 가장 비슷한 두 개의 그림을 찾아내는 프로그램을 작성하시오. 두
개의 그림에서 다른 칸의 개수가 가장 적을 때, 두 개의 그림이 가장 비슷하다고 하자. 예를 들어 위와 같은 두 개의 그림이 주어졌을
때, 색칠한 부분이 서로 다르게 된다. 위의 그림은 5개의 칸이 서로 다르다. 이와 같이 서로 다른 칸의 개수가 가장 작은 경우를 찾는
것이다.
@ Input: 첫째 줄에 N이 주어진다. 다음 5×N개의 줄에 7개의 문자로 각각의 그림이 주어진다.
@ Output: 첫째 줄에 가장 비슷한 두 그림의 번호를 출력한다. 그림의 번호는 입력되는 순서대로 1, 2, …, N이다. 번호를 출력할 때에는 작은
것을 먼저 출력한다. 입력은 항상 답이 한 가지인 경우만 주어진다.
==============================================================================================
'''

import math


N = int(input())


pics = []

for i in range(0, N):
    pic = []
    for j in range(0, 5):
        pic.append(input())
    pics.append(pic)


min_diff = math.inf
x = -1
y = -1

for k1 in range(0, N):
    for k2 in range(k1 + 1, N):
        diff = 0
        for i in range(0, 5):
            for j in range(0, 7):
                if pics[k1][i][j] != pics[k2][i][j]:
                    diff += 1

        if min_diff > diff:
            min_diff = diff
            x = k1 + 1
            y = k2 + 1

print(f"{x} {y}")
