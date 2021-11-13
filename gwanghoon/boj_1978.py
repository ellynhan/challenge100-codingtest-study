import math

num=int(input())
data=list(map(int,input().split()))
num_list=list(range(2,1001)) 
cnt=0

for i in range(2,math.ceil(math.sqrt(1000))):   #ceil = 올림
    for j in num_list:
        if j/i == 1:   
            pass
        elif j%i==0: 
            num_list.remove(j)  
for k in data:
    if k in num_list:
        cnt+=1
print(cnt)  
