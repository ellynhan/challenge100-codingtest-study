import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N, K = map(int, input().split())
arr = deque([i+1 for i in range(N)])
answer = []
cnt = 0
while arr:
    temp = arr.popleft()
    cnt += 1
    if cnt == K:
        answer.append(temp)
        cnt = 0
    else:
        arr.append(temp)        
    


print('<',end='')
for i in range(len(answer)):
    if i == len(answer)-1:
        print(answer[i],end='')
    else:
        print(answer[i],end='')
        print(',',end=' ')    

print('>')