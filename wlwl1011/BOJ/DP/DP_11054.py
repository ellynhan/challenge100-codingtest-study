import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())
arr = list(map(int, input().split()))
d_bigger = [1]*(N)
d_smaller = [0]*(N)

for i in range(N):
    #print(i)
    for j in range(i):
        if arr[i] > arr[j]:
            d_bigger[i] = max(d_bigger[i],d_bigger[j]+1)

for i in range(N-1,-1,-1):   
    for j in range(N-1,i-1,-1):
        if arr[i] > arr[j]:
            d_smaller[i] = max(d_smaller[i],d_smaller[j]+1)
            
    # print("d_bigger")    
    # print(d_bigger)         
    # print("d_smaller")    
    # print(d_smaller) 
answer = 0
for i in range(N):
    answer = max(answer, d_bigger[i] + d_smaller[i])

print(answer)