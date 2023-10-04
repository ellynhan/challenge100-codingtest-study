import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq

N, M = map(int, input().split())
cnt = [0] * (N+1)
arr = [[] for _ in range(N+1)]
queue = []
for _ in range(M): #먼저푸는게 좋은 문제 정보
    first, second = map(int, input().split())
    arr[first].append(second)
    cnt[second] +=1

for i in range(1,N+1):
    if cnt[i] == 0:
        heapq.heappush(queue,i)

while queue:
    problem = heapq.heappop(queue)
    print(problem, end=' ')
    for i in arr[problem]:
        if cnt[i] > 0:
            cnt[i] -= 1
            if cnt[i] == 0:
                heapq.heappush(queue,i)




