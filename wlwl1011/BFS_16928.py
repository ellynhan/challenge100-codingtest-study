import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

#착한 칸이 사다리면, 사다리를 타고 위로 올라간다. ->  원래 있던 칸의 번호보다 크고
# 뱀이 있는 칸에 도착하면, 뱀을 따라서 내려가게 된다. ->  원래 있던 칸의 번호보다 작아진다.

n, m = map(int, input().split())

#1부터 100번째 칸 방문 횟수
board = [0] * 101
#맵 방문 표시
visited = [False] * 101

#사다리, 뱀 딕셔너리 선언
ladder = dict()
snake = dict()

#사다리 정보 입력 받기
for _ in range(n):
    a, b = map(int, input().split())
    ladder[a] = b
for _ in range(m):
    a, b = map(int, input().split())
    snake[a] = b

q = deque([1])

while q:
    x = q.popleft()
    #100번 칸에 도착했다면
    if x == 100:
        print(board[x])
        break

    #주사위에 있는 1 부터 6까지 차례대로 입력 받아
    for dice in range(1,7):
        #다음으로 이동할 위치 보기
        next_place = x + dice
        #맵을 벗어나지 않거나 아직 방문하지 않은 칸이라면
        if next_place <= 100 and not visited[next_place]:
            #이동할 위치에 사다리가 있다면
            if next_place in ladder.keys():
                next_place = ladder[next_place]
            #이동할 위치에 뱀이 있다면
            if next_place in snake.keys():
                next_place = snake[next_place]
            #이동할 위치에 아무것도 없다면
            if not visited[next_place]:
                #방문 표시
                visited[next_place] = True
                #주사위 굴린 횟수 추가
                board[next_place] = board[x] + 1
                q.append(next_place)        


