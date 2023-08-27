import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
atexit.register(lambda : os.write(1,stdout.getvalue() ))

N = int(input())
d = [0] * (N+1)
d[0] = 0
d[1] = 1

for i in range(2,N+1):

    d[i] = d[i-1] + d[i-2]
    #print(d)
print(d[N])
