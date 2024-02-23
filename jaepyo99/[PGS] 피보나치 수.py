def pivo(n):
    global visit
    
def solution(n):
    global visit
    visit=[0 for _ in range(n+1)]
    visit[0]=0
    visit[1]=1
    for i in range(2,n+1):
        visit[i]=visit[i-1]+visit[i-2]
    return visit[n]%1234567
