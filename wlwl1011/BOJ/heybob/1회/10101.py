import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


arr = [0,0,0]

for i in range(3):
    arr[i] = int(input())

arr.sort()

if arr[0] == 60 and arr[1] == 60 and arr[2] == 60:
    print('Equilateral')
elif sum(arr)==180 and (arr[0]==arr[1] or arr[1]==arr[2]):
    print('Isosceles')   
elif sum(arr)==180 and arr[0] != arr[1] and arr[1] != arr[2]:
    print('Scalene')    
elif sum(arr) != 180:
    print('Error')    