import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = input()
stack = []
answer = 0
for i in range(len(S)):
    if S[i] == '(':
        stack.append(S[i])
    else:
        if i-1 >=0 and S[i-1] == '(':    #레이저임
            if len(stack):
                stack.pop()
                answer += len(stack)
        else:
            if len(stack):
                stack.pop()
                answer += 1
print(answer)                        