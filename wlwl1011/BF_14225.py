import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))


N = int(input())
arr = list(map(int, input().split()))
arr.sort()
flag = 0
answer = 0
for i in range(N):
    if arr[i] - answer > 1:
        print(answer + 1)
        flag = 1
        break
    answer += arr[i]
if flag == 0:    
    print(answer+1)    
     