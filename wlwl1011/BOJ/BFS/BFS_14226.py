import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))
from collections import deque

n = int(input())
emoji = [0]*(n*2)
visited = [0]*(n*2)
queue = deque()

#(현재 이모티콘의 개수, 클립보드에 있는 개수)
queue.append((1,0))

visited = dict()
visited[(1,0)] = 0

#너비 우선 탐색

while queue:

    now, clip = queue.popleft()
    #현재 이모티콘 개수가 s개 라면
    if now == n:
        #걸린 시간 출력
        print(visited[(now, clip)])
        break
    #화면에 있는 이모티콘 모두 복사하기
    if (now, now) not in visited.keys():
        visited[(now, now)] = visited[(now, clip)] + 1
        queue.append((now, now))
    #클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
    if (now + clip, clip) not in visited.keys():
        visited[(now + clip, clip)] = visited[(now, clip)] + 1
        queue.append((now+clip,clip))
    #화면에 있는거 하나 삭제하기
    if now-1 > 0 and (now-1, clip) not in visited.keys():
        visited[(now-1, clip)] = visited[(now, clip)] + 1
        queue.append((now-1, clip))        
