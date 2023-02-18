'''
==============================================================================================
@ Title: 0의 개수
@ URL: https://www.acmicpc.net/problem/11170
@ Author: jopemachine
@ Created Date: 12/6/2022, 10:40:26 PM
@ Tags: bruteforcing implementation math
@ Level: Bronze 1
@ Description:
N부터 M까지의 수들을 종이에 적었을 때 종이에 적힌 0들을 세는 프로그램을 작성하라. 예를 들어, N, M이 각각 0, 10일 때
0을 세면 0에 하나, 10에 하나가 있으므로 답은 2이다.
@ Input: 첫 번째 줄에 테스트 케이스의 수 T가 주어진다. 각 줄에는 N과 M이 주어진다. 1 ≤ T ≤ 20 0 ≤ N ≤ M ≤
1,000,000
@ Output: 각각의 테스트 케이스마다 N부터 M까지의 0의 개수를 출력한다.
==============================================================================================
'''

T = int(input())


def get_zero_cnt(num):
    cnt = 0

    for ch in str(num):
        if ch == '0':
            cnt += 1

    return cnt


for i in range(0, T):
    N, M = list(map(int, input().split()))
    zero_cnt = 0
    for j in range(N, M + 1):
        zero_cnt += get_zero_cnt(j)
    print(zero_cnt)
