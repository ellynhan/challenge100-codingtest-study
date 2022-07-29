import sys

input = sys.stdin.readline

n = int(input())

lst = []

for _ in range(n):
    a, b = input().split()
    
    lst.append([int(a), b])

# print(lst)

lst.sort(key= lambda x : x[0])

for i in lst:
    print(i[0], i[1])
    