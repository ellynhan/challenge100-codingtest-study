
import sys

n = int(input())
m = int(input())
inp = list(map(int,sys.stdin.readline().rstrip().split()))

inp.sort()
cnt = 0
i = 0
j = n-1
while i < j :
    if inp[i] + inp[j] == m:
        cnt+=1
        i+=1
        j-=1
    elif inp[i]+inp[j] < m:
        i+=1
    else:
        j-=1

print(cnt)
