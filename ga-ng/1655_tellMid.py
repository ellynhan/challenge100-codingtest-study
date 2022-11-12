import sys
import heapq

# 1   
# 1 5 
# 1 2 5   
# 1 2 5 10    
# -99 1 2 5 10    
# -99 1 2 5 7 19  
# -99 1 2 5 7 10  
# -99 1 2 5 5 7 10    

input = sys.stdin.readline
n = int(input())

left = []
right = []
ans = []

for i in range(n):
    num = int(input().rstrip())
    
    if len(left) == len(right):
        heapq.heappush(left, (-num, num))
    else:
        heapq.heappush(right, (num, num))
    

    if right and left[0][1] > right[0][1]:
        max = heapq.heappop(left)[1]
        min = heapq.heappop(right)[1]
        heapq.heappush(left, (-min, min))
        heapq.heappush(right, (max, max))

    print(left[0][1])
        
    
# print(heapq.heappop(lst))   ## 최소 힙