import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
seq = list(map(int, input().split()))
s = []
ans = [0 for _ in range(N)]
for i in range(N-1,-1,-1):
    
    while s and s[-1] <= seq[i]:
        s.pop()
    if not s:
        ans[i] = -1
    else:
        ans[i] = s[-1]
      
    s.append(seq[i])            

print(*ans)