import sys
input = sys.stdin.readline

N, M = map(int,input().split())
NumList = list(map(int,input().split()))

prefix = [0 for _ in range(N)]
prefix[0] = NumList[0]

for i in range(1, N):
    prefix[i] = prefix[i-1] + NumList[i]

for _ in range(M):
    i, j = map(int, input().split())
    
    if i == 1:
        print(prefix[j-1])
    else:
        print(prefix[j-1] - prefix[i-2])
