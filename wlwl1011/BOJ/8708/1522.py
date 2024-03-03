# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
# atexit.register(lambda : os.write(1, stdout.getvalue()))

arr = list(input())
numberOfA=arr.count('a')
arr = arr + arr[:numberOfA-1]

min_val = int(1e9)
for i in range(len(arr)):
    if i+numberOfA > len(arr):
        break
    min_val =  min(min_val,arr[i:i+numberOfA].count('b'))

print(min_val)