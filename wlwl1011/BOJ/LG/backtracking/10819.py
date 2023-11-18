import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import permutations

N = int(input())
arr = list(map(int, input().split()))

answer = 0
for a in permutations(arr,N):
    temp_answer = 0
    for i in range(0,N-1):

        temp_answer += abs(a[i] - a[i+1])
    answer = max(temp_answer, answer)    
print(answer)    