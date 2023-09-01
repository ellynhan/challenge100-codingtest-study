import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#굴다리의 길이
N = int(input())

#가로등의 개수
M = int(input())

#가로등의 위치
x = list(map(int,input().split()))

arr = [0] * (N+1)
start = 0
end = 0
for i in range(1,N+1):
    temp = []
    for index in x:
        #왼쪽
        if index - i <= 0 :
            start = 0
        else:
            start = index - i 
        if len(temp) > 0:
            if start - temp[-1] <= 0: 
                temp.append(start)
            else:
                break
        else:
            temp.append(start)    

        #오른쪽
        if index + i >= N :
            end = N 
        else:
            end = index + i
        temp.append(end)    

    #print(temp)
    if temp[0] == 0 and temp[-1] >= N:
        print(i)
        break