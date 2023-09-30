import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

for i in range(int(input())):
    s = list(input())
    stack = []
    for i in range(len(s)):
        if s[i] == '(':
            stack.append('(')
        else:
            if stack and stack[-1] == '(':
                stack.pop() 
            else:
                stack.append(s[i])     
    if stack:
        print('NO')
    else:
        print('YES')                  

