
N = int(input())
M = int(input())
arr = [ [ 0 for _ in range(N)] for _ in range(N) ]
for i in range(N):
    arr[i] = list(map(int, input().split()))

plan = list(map(int, input().split()))

parent = [ i for i in  range(N) ] #우선 자기 자신을 부모로 한다.

def find(x):
    if parent[x] != x: 
        parent[x] = find(parent[x])
    return parent[x] 
        

def union(x,y):
    x = find(x) 
    y = find(y) #이미 연결된 사이
    if x < y:
        parent[y] = x
    else:
        parent[x] = y    

for i in range(N):
    for j in range(N):
        if arr[i][j] == 1: #연결되어 있으면, 합치세요
            union(i,j)        

check = parent[plan[0]-1]
flag = True
for i in range(1,M):
    if parent[plan[i]-1] != check:
        flag = False
        break
if flag:
    print('YES')        
else:
    print('NO')    

