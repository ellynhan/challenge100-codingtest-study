from collections import deque
def dfs(answer,visit,n,m):
    if(sum(visit)==m):
        for a in range(1,len(answer)):
            print(answer[a],end=' ')
        print()
        return
    for i in range(1,n+1):
        if(visit[i]==False and answer[-1]<i):
            visit[i]=True
            answer.append(i)
            dfs(answer,visit,n,m)
            answer.pop()
            visit[i]=False

n,m=map(int,input().split())
visit=[False]*(n+1)
answer=[0]
dfs(answer,visit,n,m)
