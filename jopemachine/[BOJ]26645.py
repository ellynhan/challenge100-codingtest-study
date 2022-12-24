'''
==============================================================================================
@ Title: 성장의 비약 선택권
@ URL: https://www.acmicpc.net/problem/26645
@ Author: jopemachine
@ Created Date: 12/24/2022, 12:25:38 PM
@ Level: Bronze 3
==============================================================================================
'''

N = int(input())

if N >= 229:
    print(4)
else:
    cands = [
        min(max(209 - N + 1, 0), 8),
        min(max(219 - N + 1, 0), 4),
        min(max(229 - N + 1, 0), 2)
    ]

    ans = None
    curr = -1
    for i, v in enumerate(cands):
        if v >= curr:
            ans = i
            curr = v

    print(ans + 1)
