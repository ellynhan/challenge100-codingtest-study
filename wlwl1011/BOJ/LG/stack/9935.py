import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = list(input())
check = list(input())
stack = []

for i in s:
    stack.append(i)

    if stack[len(stack)-len(check):len(stack)] == check:
        for _ in range(len(check)):
            stack.pop()

if stack:
    print(*stack,sep='')
else:
    print('FRULA')                