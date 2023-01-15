import sys
input = sys.stdin.readline


def bt(idx, num, plus, minus, mul, div):
    global maxAns, minAns
    
    if idx == n:
        if maxAns < num:
            maxAns = num
        if num < minAns:
            minAns = num
        return 
    
    if plus > 0:
        bt(idx+1, num + nums[idx], plus-1, minus, mul, div)
    if minus > 0:
        bt(idx+1, num - nums[idx], plus, minus-1, mul, div)
    if mul > 0:
        bt(idx+1, num * nums[idx], plus, minus, mul-1, div)
    if div > 0:
        bt(idx+1, int(num / nums[idx]), plus, minus, mul, div-1)
        
n = int(input())

nums = list(map(int, input().split()))
plus, minus, mul, div = map(int, input().split())

maxAns, minAns = -1e9, 1e9
bt(1, nums[0], plus, minus, mul, div)

print(maxAns)
print(minAns)
