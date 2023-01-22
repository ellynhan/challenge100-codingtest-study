'''
==============================================================================================
@ Title: 이진수 덧셈
@ URL: https://www.acmicpc.net/problem/2729
@ Author: jopemachine
@ Created Date: 1/22/2023, 4:12:12 PM
@ Tags: arithmetic implementation math
@ Level: Bronze 1
@ Description:
이진수 덧셈은 매우 간단하고, 십진수 덧셈과 비슷하게 하면 된다. 십진수 덧셈을 할 때는, 오른쪽부터 왼쪽으로 차례대로 숫자 하나씩
더하면 된다. 이진수 덧셈도 이와 비슷하게 하면 된다. 십진수 덧셈은 외워야 할 덧셈이 많지만, 이진수 덧셈은 아래와 같이 5가지만
기억하면 된다. 0 + 0 = 0 1 + 0 = 1 0 + 1 = 1 1 + 1 = 10 1 + 1 + 1 = 11 두 이진수가
주어졌을 때, 그 합을 이진수로 출력하는 프로그램을 작성하시오.
@ Input: 첫째 줄에 테스트 케이스의 수 T(1<=T<=1,000)가 주어진다. 각 테스트 케이스는 숫자 2개로 이루어져있다. 이 숫자는 0과
1로만 이루어진 이진수이며, 길이는 최대 80자리이다. (덧셈 결과는 81자리가 될 수도 있다) 이진수는 0으로 시작할 수도 있다.
@ Output: 각 테스트 케이스에 대해 입력으로 주어진 두 이진수의 합을 구해 이진수로 출력한다. 숫자의 앞에 불필요한 0이 붙으면 안 된다.
==============================================================================================
'''

T = int(input())

for _ in range(T):
    A, B = map(list, input().split())
    C = []
    M = max(len(A), len(B))

    A = ['0'] * (M - len(A)) + A
    B = ['0'] * (M - len(B)) + B
    # print(A)
    # print(B)

    up = False
    for i in range(M - 1, -1, -1):
        if A[i] == '0' and B[i] == '0':
            if up:
                C.append(1)
            else:
                C.append(0)
            up = False

        elif A[i] == '1' and B[i] == '1':
            if up:
                C.append(1)
            else:
                C.append(0)
            up = True

        else:
            if up:
                C.append(0)
                up = True
            else:
                C.append(1)
                up = False

    if up:
        C.append(1)

    res = ''.join(map(str, reversed(C)))

    try:
        print(res[res.index('1'):])
    except ValueError:
        print(0)
