from collections import deque
def make(n):
    return [[0 for i in range(n+1)] for i in range(n+1)] 
def bfs(frame,w,n):
    visit=[False]*(n+1)
    visit[w[0]]=True
    visit[w[1]]=True
    cnt=1
    d=deque([w[0]])
    while(d):
        v=d.popleft()
        for idx,value in enumerate(frame[v]):
            if(value==0 or visit[idx]==True):
                continue
            cnt+=1
            visit[idx]=True
            d.append(idx)
    return cnt
    
    
def solution(n, wires):
    frame=make(n)
    answer=1000
    for w in wires:
        frame[w[0]][w[1]]=1
        frame[w[1]][w[0]]=1
    for w in wires:
        tmp=bfs(frame,w,n)
        answer=min(answer,abs(n-tmp-tmp))
    return answer