import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

tri = []
for i in range(3):
    tri.append(int(input()))

tri.sort()

if tri[0] == tri[1] == tri[2] == 60:
    print('Equilateral')
elif sum(tri)==180:
    if tri[0] == tri[1] or tri[1] == tri[2]:
        print('Isosceles')    
    elif tri[0] != tri[1] != tri[2]:
        print('Scalene')   
else:
    print('Error')   
