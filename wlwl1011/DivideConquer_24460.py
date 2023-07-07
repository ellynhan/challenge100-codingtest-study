import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

#특별상을 받을 수 있는 사람이 한 명이라면, 그 사람이 뽑힌다.
#그렇지 않은 경우, 대회장을 같은 크기의 정사각형 네 개로 나누어 각 구역에서 
#이 규칙을 재귀적으로 적용해서 구역마다 한 명씩 총 네 명을 뽑는다.
#뽑힌 네 명 중 의자에 적힌 추첨번호가 두 번째로 작은 사람이 뽑힌다.

def special_award(x, y, n):

    if n == 1:
        return arr[x][y]
    else:
        n = n // 2
        second_minimum = [special_award(x,y,n),special_award(x,y+n,n),special_award(x+n,y,n),special_award(x+n,y+n,n)]
        second_minimum.sort()
        return second_minimum[1]

N = int(input())
arr = [ [0 for i in range(N)] for i in range(N) ]


for i in range(N):
    arr[i] = list(map(int, input().split()))


print(special_award(0, 0, N))


