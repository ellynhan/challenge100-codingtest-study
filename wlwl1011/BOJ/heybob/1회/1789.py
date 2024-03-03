import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = int(input())

sum = 0
i = 0 

while True:

    if sum > S:
        break
    i+= 1
    sum += i
    

print(i-1)