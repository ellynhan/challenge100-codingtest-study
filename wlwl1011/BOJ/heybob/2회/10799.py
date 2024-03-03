import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

stack = []

laser_bar = input()
answer = 0
stack.append(laser_bar[0])
for i in range(1,len(laser_bar)):
    #print(laser_bar[i],stack)
    if laser_bar[i] == ')':
        if laser_bar[i-1] == '(' : #레이저다!
            stack.pop()
            answer += len(stack)
        else:
            stack.pop()
            answer +=1
    else:
        stack.append(laser_bar[i])      
    #print('answer: ',answer)      

print(answer)                