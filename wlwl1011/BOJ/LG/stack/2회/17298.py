N = int(input())

arr = list(map(int, input().split()))

stack = []
answer = []
for i in range(N-1,-1,-1):
    a = arr[i]
    while stack and stack[-1] <= a:
        stack.pop()
    if not stack:
        answer.append(-1)
    else:
        answer.append(stack[-1])
    stack.append(a)
print(*answer[::-1])               