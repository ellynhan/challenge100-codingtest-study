n=int(input())
arr_n=list(map(int,input().split()))
result=[0]*20000001
for v in arr_n:
    result[v]=1

m=int(input())
arr_m=list(map(int,input().split()))
for v in arr_m:
    if(result[v]>0):
        print("1",end=" ")
    else:
        print("0",end=" ")
