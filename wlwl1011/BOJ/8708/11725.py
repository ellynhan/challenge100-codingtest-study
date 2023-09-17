#BFS 풀이 
from collections import deque
import sys
input=sys.stdin.readline


N=int(input())
visited=[False]*(N+1)
answer=[0]*(N+1)
E=[[] for _ in range(N+1)]
for i in range(N-1):
    S,D=map(int,input().split())
    E[S].append(D)
    E[D].append(S)


def bfs(E,v,visited):
    que=deque([v])
    visited[v]=True
    while que:
        x=que.popleft()
        for i in E[x]:
            if not visited[i]:
                answer[i]=x
                que.append(i)
                visited[i]=True
           

            
bfs(E,1,visited)

for i in range(2,N+1):
        print(answer[i])