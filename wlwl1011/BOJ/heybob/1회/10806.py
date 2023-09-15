import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
check = list(map(int, input().split()))

dictionary = dict()

for i in arr:
    if i in dictionary:
        dictionary[i] += 1
    else:
        dictionary[i] = 1
ans = []
for i in check:
    if i in dictionary:
        ans.append(dictionary[i]) 
    else:
        ans.append(0)           

print(*ans)            
