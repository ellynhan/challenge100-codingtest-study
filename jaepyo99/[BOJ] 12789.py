from collections import deque
n=int(input())
lines=list(map(int,input().split()))
wait=deque([])
num=1
for line in lines:
    wait.append(line)

    while(len(wait)!=0 and wait[-1]==num):
        wait.pop()
        num+=1
if(len(wait)>0):
    print("Sad")
else:
    print("Nice")
        
