import sys

input = sys.stdin.readline

k = int(input())

lst = []

for _ in range(k):
    temp = int(input().rstrip())
    
    if temp != 0:
        lst.append(temp)
    else:
        lst.pop()
        
print(sum(lst))
    