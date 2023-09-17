import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())

for _ in range(T):
    temp = []
    PS = list(input())
    flag = True
    while PS:
        #print('PS' ,PS)
        #print('temp',temp)
        if PS[-1] == ')':
            temp.append(PS.pop())
        else:
            if len(temp)>=1 and temp[-1] == ')':
                temp.pop()
                PS.pop()
            else:
                PS.pop()
                flag = False
    if temp:
        print('NO')            
    elif flag:
        print('YES')
    else:
        print('NO')                 


