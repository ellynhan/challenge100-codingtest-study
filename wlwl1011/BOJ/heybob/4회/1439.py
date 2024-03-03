import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = list(map(int, input()))

count_0 = 0
count_1 = 0

if S[0] == 1:
    count_1 += 1
else:
    count_0 += 1    


for i in range(1,len(S)):
    if S[i-1] != S[i]:
        if S[i] == 1:
            count_1 += 1
        else:
            count_0 += 1    

print(min(count_0, count_1))