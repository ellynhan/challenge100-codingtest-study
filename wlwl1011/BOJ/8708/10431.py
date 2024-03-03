import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque


P=int(input())
for _ in range(P):
    arr=list(map(int,input().split()))
    total=0
    for i in range(1,len(arr)-1):
        print(arr[i])
        for j in range(i+1,len(arr)): # i 뒤에 애들과 전부 비교해서
            if arr[i] > arr[j]:  # i가 더 크면
                arr[i],arr[j] = arr[j],arr[i]  # 자리바꾸기
                total+=1
            print(arr)    
    print(arr[0], total)
