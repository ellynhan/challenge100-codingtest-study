n = int(input())
numbers = list(map(int, input().split()))

answer = [-1] * n
stack = []
for i in range(n):
    while stack and numbers[stack[-1]] < numbers[i]:
        answer[stack.pop()] = numbers[i]
    stack.append(i)

print(*answer)
