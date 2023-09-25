import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

s = input()

index = 0
ans = []
stack = []
while len(s)>index:
    if s[index] == '<':
        if stack:
            while stack:
                ans.append(stack.pop())
        while True:
            ans.append(s[index])
            index += 1
            if s[index] == '>':
                ans.append(s[index])
                break
            
    elif s[index] == ' ':
        while stack:
            ans.append(stack.pop())
        ans.append(s[index])    
    else:       
        stack.append(s[index])  
    index += 1    
if stack: 
     while stack:
        ans.append(stack.pop())    

for i in range(len(ans)):   
    print(ans[i],end='')              
    