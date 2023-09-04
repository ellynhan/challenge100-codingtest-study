import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

while(1):
    tri = []
    tri = list(map(int, input().split()))
    
    if tri[0]==0 and tri[1]==0 and tri[2]==0:
        break

    tri.sort()
    #print(tri)
    #가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 길어야함
    if tri[2] < tri[0] + tri[1]:
        if tri[2] == tri[0] == tri[1]:
            print("Equilateral")
        elif tri[2] == tri[1] or tri[0] == tri[1] :
            print("Isosceles")
        else:
            print("Scalene")    
    else:
        print("Invalid")
             
    
