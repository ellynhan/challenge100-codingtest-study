import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

def solution(r, c, k, area):                        # 시작 좌표, 제곱 수, 구역
    global num

    if k <= 1:                                      # 가장 안쪽 단계이면
        cnt = 3                                     # ㄱ자 모양 타일은 3개만 채워야 하므로
        if area == 0 or area == 4:                  # 왼쪽 위와 가운데 영역
            for i in range(r, r+2):                 # 위에서 아래, 왼쪽에서 오른쪽
                for j in range(c, c+2):
                    if not board[i][j] and cnt:
                        board[i][j] = num
                        cnt -= 1
        elif area == 1:                             # 오른쪽 위에 영역
            for i in range(r, r+2):                 # 위에서 아래, 오른쪽에서 왼쪽
                for j in range(c+1, c-1, -1):
                    if not board[i][j] and cnt:
                        board[i][j] = num
                        cnt -= 1
        elif area == 2:                             # 왼쪽 아래 영역
            for i in range(r+1, r-1, -1):           # 아래에서 위, 왼쪽에서 오른쪽
                for j in range(c, c+2):
                    if not board[i][j] and cnt:
                        board[i][j] = num
                        cnt -= 1
        elif area == 3:                             # 오른쪽 아래 영역
            for i in range(r+1, r-1, -1):           # 아래에서 위, 오른쪽에서 왼쪽
                for j in range(c+1, c-1, -1):
                    if not board[i][j] and cnt:
                        board[i][j] = num
                        cnt -= 1
        num += 1
        return
    
    solution(r, c, k-1, 0)                          # 각 영역으로 재귀, 분할정복
    solution(r, c + 2**(k-1), k-1, 1)
    solution(r + 2**(k-1), c, k-1, 2)
    solution(r + 2**(k-1), c + 2**(k-1), k-1, 3)
    solution(r + 2**k//4, c + 2**k//4, k-1, 4)



K = int(sys.stdin.readline())                       # 제곱수
X, Y = map(int, sys.stdin.readline().split())       # 하수구 구멍의 좌표
board = [[0] * 2**K for _ in range(2**K)]           # 샤워실 바닥
board[2**K - Y][X - 1] = -1                         # 하수구 구멍 -1 표시

num = 1                                             # 타일 번호

solution(0, 0, K, 0)                                # 분할정복 시작

for row in board:                                   # 출력
    for col in row:
        print(col, end=' ')
    print()