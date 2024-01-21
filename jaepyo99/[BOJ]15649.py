def dfs(visit,arr,n,m,cnt,buc):
    if(cnt==m):
        for i in range(len(buc)):
            print(buc[i],end=' ')
        print()
        return
    for idx,b in enumerate(arr):
        if(visit[idx]==False):
            
            visit[idx]+=1
            buc.append(arr[idx])
            dfs(visit,arr,n,m,cnt+1,buc)
            visit[idx]-=1
            buc.pop()

n,m=map(int,input().split())
arr=[i for i in range(1,n+1)]
visit=[0]*n
buc=[]
dfs(visit,arr,n,m,0,buc)