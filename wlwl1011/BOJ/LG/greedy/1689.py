import sys

input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
events = []

for _ in range(N):
    s, e = map(int, input().split())
    events.append((s, 1))  # 선분의 시작 좌표에 대한 이벤트
    events.append((e, -1)) # 선분의 끝나는 좌표에 대한 이벤트

events.sort()  # 이벤트 정렬

count = 0  # 현재 겹치는 선분의 개수
max_count = 0  # 최대 겹치는 선분의 개수

for s, event in events:
    
    count += event
   
    max_count = max(max_count, count)

print(max_count)