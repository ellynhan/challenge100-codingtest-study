import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())

arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

# for i in range(N):
#     print(arr[i])

for i in range(1,N):
    #print('index:',i)
    for j in range(len(arr[i])):
        #print(len(arr[i]))
        if j == 0:
            arr[i][j] = arr[i-1][j] + arr[i][j]
        elif j == len(arr[i])-1:    
            arr[i][j] = arr[i-1][j-1] + arr[i][j]
        else:    
            arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + arr[i][j]   
    #print(arr[i])        

print(max(arr[N-1]))