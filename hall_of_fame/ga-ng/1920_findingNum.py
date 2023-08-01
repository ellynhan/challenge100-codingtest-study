import sys
from bisect import bisect_right, bisect_left
    
input = sys.stdin.readline

n = int(input())
nArr = list(map(int, input().split()))
nArr.sort()

nx = int(input())
xArr = list(map(int, input().split()))

for i in xArr:
    start = 0
    end = n - 1
    isInThere = False
    
    while start <= end:
        
        mid = (start + end) // 2
        
        if i == nArr[mid]:
            isInThere = True
            print(1)
            break
        elif i > nArr[mid]:
            start = mid + 1
        else:
            end = mid - 1
            
    if not isInThere:
        print(0)