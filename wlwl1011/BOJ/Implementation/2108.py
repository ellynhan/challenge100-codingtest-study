import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N  = int(input())
arr = [0 for _ in range(N)]
dictionary = dict()

for i in range(N):
    arr[i] = int(input())
    if arr[i] in dictionary:
        dictionary[arr[i]] += 1
    else:
        dictionary[arr[i]] = 1    

dictionary = dict(sorted(dictionary.items(), key= lambda x:x[1], reverse=True))

arr.sort()  
print(round(sum(arr)/N))
print(arr[N//2])
cnt = 0
more_k = 0
ans = []

for key, value in dictionary.items():
    cnt += 1
    if cnt == 1:
        more_k = key
        more_v = value
        ans.append(key)
    else:
        if more_v == value:
            more_k = key
            ans.append(key)
        else:
            break    
ans.sort()
if cnt >2:
    print(ans[1])
else:
    print(ans[0])    
print(arr[N-1]-arr[0])
