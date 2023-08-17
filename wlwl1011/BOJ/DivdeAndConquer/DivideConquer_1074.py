import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

#배열을 z 모양으로 탐색

N, r, c = map(int, input().split())

answer = 0

while N != 0:
    
    N -= 1

    #1사분면
    if r < 2 ** N and c < 2 ** N:
        answer += (2**N) * (2**N) * 0

    #2사분면
    elif r < 2 ** N and c >= 2 ** N :
        answer += ( 2 ** N ) * ( 2 ** N ) * 1
        c -= ( 2 ** N )

    #3사분면
    elif r >= 2 ** N and c < 2 ** N: 
        answer += ( 2 ** N ) * ( 2 ** N ) * 2
        r -= ( 2**N)
    else:
        answer += ( 2 ** N ) * ( 2 ** N ) * 3
        r -= ( 2**N)
        c -= ( 2 ** N )     

print(answer)                 