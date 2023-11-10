import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = input()
if s == '.':
    print('no')
else:    

    while s != '.':
        stack = []
        flag = True
        for i in range(len(s)-1): #맨끝은 온점으로 끝
           
            if s[i] == '(' or s[i] == '[':
                stack.append(s[i])
            elif s[i] == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                
                else:
                    print('no')
                    flag = False
                    break
            elif s[i] == ']':
                if stack and stack[-1] == '[':
                    stack.pop()    
                else:
                    flag = False
                    print('no')
                    break    
        if stack and flag:
            print('no')
        elif flag :
            print('yes')    
        s = input()    
   

