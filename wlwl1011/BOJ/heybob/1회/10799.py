import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


batch = input() #냅다 입력을 받습니다.
stack = []
laser = []
bar = []

for i in range(len(batch)):
    #print(stack)
    if len(stack) == 0: #비었으면
        stack.append((batch[i],i))
    else:
        if batch[i] == '(' :# 열림이면 넣고.
            stack.append((batch[i],i))
        else: #닫힘이냐
           
            if stack[-1][0] == '(' and stack[-1][1] == i-1:
                laser.append(i-1) #laser의 index를 기록합니다.  
                stack.pop()   
                
            else:
                #쇠막대기 끝 부분임.
                start = stack.pop()     
                bar.append((start[1],i)) #시작과 끝부분 기록.

# print(bar)
# print(laser)
answer = 0
for start,end in bar:
    check = 0
    for ls in laser:
        if start <= ls <= end:
            check += 1
    answer += check + 1

print(answer)