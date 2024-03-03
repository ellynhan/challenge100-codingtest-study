import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, M = map(int, input().split())

arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

K = int(input())
ans = []
for _ in range(K):
    i,j,x,y = map(int, input().split())
    sum = 0
    for index_i in range(i-1,x):
        for index_j in range(j-1,y):
            sum += arr[index_i][index_j]
    ans.append(sum)    

for i in range(K):
    print(ans[i])

