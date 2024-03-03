import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

X = int(input())
line = 1

while X > line:
    X -= line
    line += 1



if line % 2 == 0:
    a = X
    b = line-X+1
else:
    a = line - X + 1
    b = X

print(a,'/',b,sep='')            

