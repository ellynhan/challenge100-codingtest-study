import sys

n = int(sys.stdin.readline())

while n != 0 :
    data = [sys.stdin.readline().rstrip() for i in range(n)]

    path = 0
    for j in list(data[0]) :
        if j == ' ' :
            path += 1
        else :
            path += 1
            break
    
    for k in range(n) :
        l = len(data[k])
        if l < path :
            continue
        temp = data[k].find(' ', path)
        if temp == -1 :
            path = l
        else :
            path = temp
    print(path+1)

    n = int(sys.stdin.readline())
