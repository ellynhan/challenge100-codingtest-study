import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = list(input())

stack = []
ans = 0
for i in range(len(s)):
    if s[i] == ')':
        if s[i-1] == '(':
            stack.pop()
            ans += len(stack)
            
        else:
            ans += 1
            stack.pop()
    else:
        stack.append(s[i])       

print(ans)             
