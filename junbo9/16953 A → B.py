a,b = map(int,input().split())
r = 1
while(b!=a):
    r+=1
    temp = b
    if b%10 == 1:
        b//=10https://github.com/junbo9/challenge100-codingtest-study/blob/master/junbo9/A%20%E2%86%92%20B.py
    elif b%2 == 0:
        b//=2
    
    if temp == b:
        print(-1)
        break
else:
    print(r)  
 
