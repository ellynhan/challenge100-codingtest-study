import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


#다른 사람들의 손 쉬운 풀이...


#레이저가 나오면, () 이면, 앞에 쌓인 ( 만큼 잘린다.
#레이저가 아닌 쇠막대기 끝 ) 이면 +1만해준다. 그게 끝에 잘린 부분임.
#지금 내 풀이는 마지막에 이중 for문을 쓰는데, 만약 입력 값의 크기가 더 커진다면 위험함.

def otherAnswer(arr):
    stack = []
    answer = 0
    for i in range(len(arr)):
        if arr[i] == '(':
            stack.append()
        else:
            if arr[i-1] == '(':
                stack.pop()
                answer += len(stack)  
            else:
                stack.pop()
                answer += 1      
    return answer



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




