import sys
input = lambda : sys.stdin.readline().strip()

N = int(input())
cnt = 0
for _ in range(N):
    s = list(input())
    stack = []
    for i in range(len(s)-1,-1,-1):
        if stack and stack[-1] == s[i]:
            stack.pop()
        else:
            stack.append(s[i])    
    if not stack:
        cnt += 1
print(cnt)        