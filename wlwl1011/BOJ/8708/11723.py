import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

M = int(input())

s = [0 for _ in range(20)]
all_s = [1 for i in range(20)]
for i in range(1,21):
    all_s.append(i)

for i in range(M):
    temp = list(input().split())
 
    if len(temp) == 1 and temp[0] == "all":
       s = all_s[:]
    elif len(temp) == 1 and temp[0] == "empty":
        s = [0 for _ in range(20)]
    elif len(temp) == 2:     
        word, number = temp[0], temp[1] 
        number = int(number)
        if word == "add":
            s[number-1] = 1
          
        elif word == "remove":
            s[number-1] = 0

        elif word == "check":
            if s[number-1] == 1:
                print(1)
            else:
                print(0)    
        elif word == "toggle":
            if s[number-1] == 1:
                s[number-1] = 0
            else:
                s[number-1] = 1  
        

