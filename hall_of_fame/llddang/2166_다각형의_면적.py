import sys

N = int(sys.stdin.readline())

arr=[]
for i in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

area = 0
for i in range(N):
    if(i == N-1): area += arr[i][0] * arr[0][1]
    else: area += arr[i][0] * arr[i+1][1]

    if(i == 0): area -= arr[i][0] * arr[N-1][1]
    else: area -= arr[i][0] * arr[i-1][1]

print(abs(area) / 2)
