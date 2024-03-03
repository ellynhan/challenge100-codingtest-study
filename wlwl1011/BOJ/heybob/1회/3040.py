import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from itertools import combinations

arr = []

for i in range(9):
    arr.append(int(input()))

arr_sum = sum(arr)

arr_sum -= 100

for i,j in combinations(arr,2):
    if i+j == arr_sum:
        arr.pop(arr.index(i))
        arr.pop(arr.index(j))

for i in arr:
    print(i)

