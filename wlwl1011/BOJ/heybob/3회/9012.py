import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())

for _ in range(T):
    S = list(input())
    stack = []
    flag = True
    for i in S:
        if i == '(':
            stack.append(i)
        else:
            if stack:
                if stack[-1] == '(':
                    stack.pop()
                else:
                    flag = False
                    break
            else:
                stack.append(i)     
    if stack:
        print('NO') 
    elif flag == False:
        print('NO')
    else:
        print('YES')                      

                    
