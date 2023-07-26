import sys

input = sys.stdin.readline

n = int(input())

command = []
stack = []

for _ in range(n):
    command.append(input().rstrip())
    
# print(command)

for i in command:
    if i == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])
    elif i == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif i == "size":
        print(len(stack))
    elif i == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    else:
        stack.append(i[5:])