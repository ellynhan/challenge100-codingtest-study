import sys
import heapq


num = int(input())
Q = []

for _ in range(num):
    digit = int(sys.stdin.readline())
    if digit != 0:
        heapq.heappush(Q, (abs(digit), digit))
    else:
        if Q:
            print(heapq.heappop(Q)[1])
        else:
            print(0)

            
