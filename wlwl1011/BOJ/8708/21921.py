import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, X = map(int, input().split())
arr = [0] + list(map(int, input().split()))

sum = [0] * (N+1)
sum[1] = arr[1]
for i in range(2,N+1):
    sum[i] += sum[i-1]+arr[i]
#print(sum)
answer = -1
check = 0
for i in range(X,N+1):
    #answer = max(answer,sum[i]-sum[i-X])
    #print(sum[i]-sum[i-X])
    if sum[i]-sum[i-X] > answer:
        answer = sum[i]-sum[i-X]
        
        check = 1
    elif sum[i]-sum[i-X] == answer:
        check += 1    
if answer == 0:
    print('SAD')
else:
    print(answer) 
    print(check)       
    
    