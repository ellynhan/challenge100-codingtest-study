import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import heapq


N = int(input())

hq = []

for _ in range(N):
    x = int(input())
    #x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우
    if x == 0:
        if len(hq) == 0:
            print(0)
        else:    
            temp = heapq.heappop(hq)
            print(temp)
    else:#만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산
        heapq.heappush(hq, x)    