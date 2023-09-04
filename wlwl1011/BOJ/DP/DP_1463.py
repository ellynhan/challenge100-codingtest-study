import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())

d = [0] * (N+1)
for i in range(2,N+1):
    #print(i)
    
    #1을 빼는 경우
    d[i] = d[i-1] + 1

    #2로 나누어 떨어지는 경우
    if i % 2 == 0:
        d[i] = min(d[i],d[i//2]+1)

    #3으로 나누어 떨어지는 경우

    if i % 3 == 0:
        d[i] = min(d[i], d[i//3]+1)

    #print(d)
print(d[N])