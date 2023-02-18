import sys
input = sys.stdin.readline


def infixToPostfix():
    postfix = ""
    stack = []
    
    for ch in infix:
        if ch.isalpha():
            postfix += ch
            continue
        
        if ch == '(':
            stack.append(ch)
            
        elif ch == '*' or ch == '/':
            while stack and (stack[-1] == '*' or stack[-1] == '/'):
                postfix += stack.pop()
            stack.append(ch)
        
        elif ch == '-' or ch == '+':
            while stack and stack[-1] != '(':
                postfix += stack.pop()
            stack.append(ch)
        
        elif ch == ')':
            while stack[-1] != '(':
                postfix += stack.pop()
            stack.pop()
    
    while stack:
        postfix += stack.pop()
    
    return postfix

infix = list(input().rstrip())

ans = infixToPostfix()

print(ans)
