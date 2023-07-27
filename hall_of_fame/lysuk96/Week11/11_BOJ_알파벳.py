# https://www.acmicpc.net/problem/1987
# 1트 : 그냥 BFS로 풀면 최솟값만 나옴
# 2트 : 거리 말고 string 자체를 보내면 되지만, 시간초과
# 3트 : 성공. q에 deque 대신 set 써줘야함

# 참고 https://devjin-blog.com/boj-1987-alphabet/

from collections import deque
R, C = map(int, input().split(" "))
board = [list(input()) for _ in range(R)]
# board = [list(map(ord,list(input()))) for _ in range(R)]
# visit = [False]*26 # -65한 값이 idx -> 사실 필요없음!
q = set([(0,0,board[0][0])]) # x,y,m

# print(*board, sep='\n')
move = [(0,1),(1,0),(-1,0),(0,-1)]
answer = 0
while q:
    x, y, string = q.pop()
    answer = max(answer, len(string))
    for i in range(4):
        nx = x + move[i][0]
        ny = y + move[i][1]
        if 0<=nx<R and 0<=ny<C:
            if board[nx][ny] not in string:
                q.add((nx,ny,string+board[nx][ny]))

print(answer)