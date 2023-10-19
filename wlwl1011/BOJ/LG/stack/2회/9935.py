import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = list(input())
bomb = list(input())

stack = []

for i in s:
    stack.append(i)
    if len(stack) >= len(bomb) and stack[len(stack)-len(bomb)::] == bomb:
        cnt = 0
        while stack:    
            stack.pop()
            cnt += 1
            if cnt == len(bomb):
                break

if not stack:
    print('FRULA')
else:
    print(*stack,sep='')        