# https://www.acmicpc.net/problem/2696
from collections import deque
from bisect import insort
T = int(input())
for _ in range(T):
    M = int(input())
    nums = []
    q = deque([])
    for _ in range(M//10+1):
        q.extend(list(map(int, input().split(" "))))

    nums.append(q.popleft()) #initialize
    n = 1
    answer = [nums[0]]
    while q:
        insort(nums, q.popleft())
        insort(nums, q.popleft())
        # print(nums)
        n+=2
        answer.append(nums[n//2])

    print(len(answer))
    for i in range(len(answer)//10+1):
        now = answer[i*10:(i+1)*10]
        print(*now)

