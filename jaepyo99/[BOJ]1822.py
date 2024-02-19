na,nb=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

minus=set(a)-set(b)
if(len(minus)==0):
    print(0)
else:
    print(len(minus))
    minus=sorted(minus)
    for i in minus:
        print(i,end=" ")
