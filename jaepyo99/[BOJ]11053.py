n=int(input())
arr=list(map(int,input().split()))
result=[0]*n
result[0]=1
for i in range(1,n):
    maxx=0
    for j in range(0,i):
        if(maxx<result[j] and arr[i]>arr[j]):
            maxx=result[j]
    result[i]=maxx+1
print(max(result))
