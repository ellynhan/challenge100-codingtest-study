def dfs(arr,n,m):
    if(len(arr)==m):
        for i in arr:
            print(i,end=' ')
        print()
        return
    for i in range(1,n+1):
        arr.append(i)
        dfs(arr,n,m)
        arr.pop()
    
n,m=map(int,input().split())
dfs([],n,m)
