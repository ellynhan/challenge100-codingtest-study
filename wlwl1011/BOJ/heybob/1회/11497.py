import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())

for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    new = [0] * N
    i,j = 0,N-1
    for index in range(N):
        if index % 2 == 0:
            new[i] = arr[index]
            i += 1
        else:
            new[j] = arr[index]    
            j -= 1
            
    #print(new)        
    ans = -int(1e9)       
    for i in range(1,N):
        ans = max(ans, abs(new[i-1]-new[i]) )
    ans = max(ans, abs(new[-1]-new[0]) )
    print(ans)    

#원리는 같지만 물리적으로 배열에 삽입하지 않고 풀이 ...
# T = int(input())
# for _ in range(T):
#     N = int(input())
#     S = list(map(int,input().split()))
#     S.sort()
#     maxv=0
#     for i in range(N-2):
#         maxv = max(maxv,abs(S[i]-S[i+2]))
#     print(maxv)
