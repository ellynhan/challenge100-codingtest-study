import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')



arr1 = []
arr2 = []

N, M = map(int, input().split())
for _ in range(N):
    arr1.append(list(map(int, input().split())))

M, K = map(int, input().split())
for _ in range(M):
    arr2.append(list(map(int, input().split())))    

arr3= [[0 for _ in range(K)] for _ in range(N)]

for i in range(N):
    for j in range(M):
        for k in range(K):
            arr3[i][k] += arr1[i][j] * arr2[j][k]
    
for i in range(N):
    print(*arr3[i])

