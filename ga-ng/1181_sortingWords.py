import sys

input = sys.stdin.readline

n = int(input())

lst = []

for _ in range(n):
    lst.append(input().rstrip())
    

lst = list(set(lst))
    
lst.sort()
lst.sort(key = len)


for i in lst:
    print(i)