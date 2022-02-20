import sys

inputStr = sys.stdin.readline().rstrip()

stack = []
while len(inputStr) != 1 or inputStr[0] !='.':
    for s in inputStr:
        if s == '(' or s == '[':
            stack.append(s)
        elif s == ')':
            if len(stack) > 0 and stack[-1] == '(':
                stack.pop()
            else :
                stack.append('e')
                break
        elif s == ']' :
            if len(stack) > 0 and stack[-1] == '[':
                stack.pop()
            else :
                stack.append('e')
                break
    if len(stack) > 0 :
        print("no")
    else:
        print("yes")
    inputStr = sys.stdin.readline().rstrip()
    stack.clear()