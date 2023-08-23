
import sys
input = sys.stdin.readline

n = int(input())
cases = list(map(int, input().split()))
lis = [-1000000001]

for case in cases:
    #print(lis)
    if lis[-1]<case:
        lis.append(case)
    else:
        left = 0
        right = len(lis)

        while left<right:
            mid = (right+left)//2
            if lis[mid]<case:
                left = mid+1
            else:
                right = mid
        lis[right] = case

print(len(lis)-1)