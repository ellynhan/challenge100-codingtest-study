import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
lst = [-1] * n

stack = deque()

for i in range(n):
    while stack and arr[stack[-1]] < arr[i]:
        lst[stack.pop()] = arr[i]
    stack.append(i)
            
print(*lst)