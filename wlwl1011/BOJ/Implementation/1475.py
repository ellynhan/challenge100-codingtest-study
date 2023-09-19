import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

plastic_number = [0 for _ in range(10)]
number = list(map(int,input()))
cnt = 1
for i in number:
 
 
    if plastic_number[i] < cnt:
        plastic_number[i] += 1 
    else:
        if i == 9 and plastic_number[6] < cnt:
            plastic_number[6] += 1
        elif i == 6 and plastic_number[9] < cnt:
            plastic_number[9] += 1
        else:
            plastic_number[i] += 1
            cnt += 1     
 
print(cnt)            