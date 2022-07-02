#
#   그래프 실버2
#   11724 연결 요소의 개수
#

import sys
from sys import stdin
sys.setrecursionlimit(10 ** 6) 


def dfs(start,depth):

    check[start] = True
    for i in (graph[start]):
        if check[i]==False:
            dfs(i,depth+1)






n, m = map(int, stdin.readline().split())
cnt = 0
graph = [[] for _ in range(n+1)]
check = [False for i in range(n+1)]
for i in range(m):
    x,y = map(int,stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)
    


for i in range(1,n+1):
    if check[i] == False:
        if not graph[i]:
            check[i]=True
            cnt+=1
        else:
            dfs(i, 0)
            cnt+=1


print(cnt)


