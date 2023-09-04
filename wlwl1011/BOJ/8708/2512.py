import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import math
N = int(input())
arr = list(map(int, input().split()))
money = int(input())

if sum(arr) <= money:
    print(max(arr))
else:
    start = 0
    end = money
    answer = 0
    while start <= end:
        mid = ( start + end ) // 2
        sum_money = 0
        for i in arr:
            if i < mid:
                sum_money += i
            else:
                sum_money += mid
         
        if sum_money <= money:
            start = mid + 1
            answer = mid
        else:
            end = mid - 1    
    print(answer)        