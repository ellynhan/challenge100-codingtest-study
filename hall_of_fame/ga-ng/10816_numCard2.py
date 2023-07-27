import sys
from bisect import bisect_left, bisect_right

input = sys.stdin.readline

n = int(input())
nArr = list(map(int, input().split()))
nArr.sort()

m = int(input())
mArr = list(map(int, input().split()))

def countCard(arr, lVal, rVal):
    lInd = bisect_left(arr, lVal)
    rInd = bisect_right(arr, rVal)
    
    return rInd - lInd

for card in mArr:
    print(countCard(nArr, card, card), end=" ")