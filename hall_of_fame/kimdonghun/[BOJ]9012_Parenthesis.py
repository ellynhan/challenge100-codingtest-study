import sys

T = int(sys.stdin.readline())

for i in range(T):
    p_list = list(sys.stdin.readline()[:-1])
    #print(p_list)

    s = []
    isVPS = True
    for p in p_list:
        if p == '(':
            s.append('(')
        else:
            if len(s) > 0:
                s.pop()
            else:
                isVPS = False
    
    #print(s)
    #print(isVPS)

    if len(s) > 0 or isVPS == False:
        print("NO")
    else:
        print("YES")
