import sys
from itertools import combinations
input = lambda : sys.stdin.readline().rstrip('\r\n')

arr = []
for _ in range(9):
    arr.append(int(input()))

dif = sum(arr) - 100    

for i,j in combinations(arr,2):
    if i+j == dif:
        for index in arr:
            if index != i and index !=j:
                print(index)