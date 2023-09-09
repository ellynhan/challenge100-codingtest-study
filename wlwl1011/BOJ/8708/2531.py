import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque 
#회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
N, d, k, c = map(int, input().split())
arr = [0 for _ in range(N)]

for i in range(N):
    arr[i] = int(input())

arr = arr[:] + arr[:k-1]


flag = True
max_len = 0
left = 0
right = 0
count = 0
first = 0
queue = deque()
falg = True
while right < len(arr):
    
    if right - left < k : #집어 넣을 수 있습니까?
        queue.append(arr[right])
        right += 1
    
    else:
        #print(queue)
        flag = False
        if c in set(queue):
            max_len = max(max_len,len(set(queue)))
        else:
            max_len = max(max_len,len(set(queue))+1)    
        queue.popleft()
        left += 1    
     
#print(count)
           
if falg:
    if c in set(queue):
        max_len = max(max_len,len(set(queue)))
    else:
        max_len = max(max_len,len(set(queue))+1)          
print(max_len)