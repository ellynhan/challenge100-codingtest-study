import sys
input = sys.stdin.readline


n = int(input())

timeTable = [(0,0)]
d = [0]*(n+2)

for _ in range(n):
    t, p = map(int, input().split())
    timeTable.append((t,p))

for i in range(n, 0, -1):
    day, cost = timeTable[i]
    if i + day <= n+1:
        d[i] = max(cost + d[i+day], d[i+1])
    else:
        d[i] = d[i+1]
    
print(d[1])
