import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())

for _ in range(T):
    S = input()
    stack = []
    flag = True
    for i in S:
        if i == '(':
            stack.append('(')
        else:
            if len(stack):
                temp = stack.pop()
                if temp != '(':
                    flag = False
                    break   
            else:
                stack.append(')')    
    
    if len(stack) !=0 :
        print('NO')
    elif not flag:
        print('NO')
    else:
        print('YES')                