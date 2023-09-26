import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

arr = []

for _ in range(3):

    arr.append(int(input()))

arr.sort()

if arr[0] == arr[1] == arr[2] == 60:
    print("Equilateral")
elif sum(arr) == 180:
    if arr[0] == arr[1] or arr[1] == arr[2]:
        print("Isosceles")    
    elif arr[0] != arr[1] != arr[2]:
        print("Scalene")    
else:
    print("Error")        


