import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = input()
check = int(S[0])
cnt_1 = 0
cnt_0 = 0

if check == 1:
    cnt_1 = 1
else:
    cnt_0 = 1    

for i in range(1,len(S)):
    if S[i-1] != S[i]:
        if int(S[i]) == 1:
            cnt_1 += 1
        else:
            cnt_0 += 1    
    
print(min(cnt_0, cnt_1))    