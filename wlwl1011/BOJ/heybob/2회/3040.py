import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from itertools import combinations

arr = []

for _ in range(9):
    arr.append(int(input()))

dif = sum(arr)-100    
possibble = [ i for i in range(1,100)]

for i,j in combinations(arr,2):
    if i != j and i+j == dif:
        for index in arr:
            if index != i and index != j:
                print(index)