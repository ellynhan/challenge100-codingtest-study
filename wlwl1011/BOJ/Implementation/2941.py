import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#다른 사람들 풀이/ replace 이용
#처음에 replace를 이용해서 풀고자했으나, ddz=z= 과 같은 문자열에서 문제발생.

def otherAnswer():
    cro_al = ['c=','c-','dz=','d-','lj','nj','s=','z=']
    for i in cro_al:
        x = x.replace(i, 'a')
    print(len(x))
 



alpabet = input()
answer = 0

stack = []

for i in range(len(alpabet)):
    
    if len(stack) == 0:
        stack.append(alpabet[i])
    else:
        if alpabet[i] == '=' or alpabet[i] == '-':
            if alpabet[i-1] == 'c' or alpabet[i-1] == 's' :
                stack.pop()
                answer += 1
            elif len(stack) >=2 and alpabet[i-1] == 'z' and alpabet[i-2] == 'd':
                stack.pop()
                stack.pop()
                answer += 1    
            elif alpabet[i-1] == 'z':
                stack.pop()
                answer += 1    
        elif alpabet[i] == 'j':
            if alpabet[i-1] == 'l' or alpabet[i-1] == 'n':
                stack.pop()
                answer += 1
            else:
                stack.append(alpabet[i])    
        else:
            stack.append(alpabet[i])
          
#print(stack)
print(answer + len(stack))                      
