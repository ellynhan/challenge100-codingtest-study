import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
import heapq
length = []
heapq.heappush(length, 64)
X = int(input())

while length:
    
    if X == sum(length):
        break
    else:
        l = heapq.heappop(length)
        l = l // 2 # 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
        heapq.heappush(length,l)
        if sum(length) >= X:
            continue
        else:
            heapq.heappush(length,l)
print(len(length))            