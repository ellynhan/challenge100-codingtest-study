# dfs 넘길때 현재 index(visit) column 넘기기


def make(n):
    return [[0 for _ in range(n+1)]for _ in range(n+1)]        

def color(co,r,c,n):
    row=r
    col=c
    for i in range(col,n+1): #옆
        co[row][i]=1
    row=r
    col=c    
    while(1):
        if(row+1<=n and col+1<=n): #아래대각
            row=row+1
            col=col+1
            co[row][col]=1
        else:
            break
    row=r
    col=c
    while(1):
        if(row-1>=1 and col+1<=n): #윗대각
            row=row-1
            col=col+1
            co[row][col]=1
        else:
            break
    return co
        
def copy(frame):
    c=[]
    for f in frame:
        c.append(f[:])
    return c
    
def dfs(frame,visit,n,c):
    global answer
    if(n==sum(visit)):
        answer+=1
        return
    for r in range(1,n+1):
        if(visit[r]==False and frame[r][c]!=1):
            visit[r]=True
            co=copy(frame)
            co=color(co,r,c,n)
            dfs(co,visit,n,c+1)
            visit[r]=False
    
global answer
answer=0
n=int(input())
frame=make(n)
visit=[False]*(n+1)
dfs(frame,visit,n,1)
print(answer)
