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

N = int(input())

arr = [ [0 for i in range(N)] for i in range(N) ]


for i in range(N):
    arr[i] = list(map(int, input().split()))

arr = []
def special_award(x_start, x_end, y_start, y_end):
    if x_start >= x_end:
        return    
    if x_start-x_end == 2:
        new_arr = []
        for i in range(x_start, x_end):
            for j in range(y_start, y_end):
                new_arr.append(arr[i][j])
        return arr.append(new_arr[1])
    special_award(x_start//2, x_end//2, y_start//2, y_end//2)
    special_award(x_start, x_end//2, y_start//2, y_end//2)
    



