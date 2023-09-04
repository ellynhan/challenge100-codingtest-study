import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, K = map(int, input().split())
arr = [0] + list(input())
check = [0] * (N + 1)
for i in range(1,N+1):
    if arr[i] == 'P': #사람일 때
        flag = True
        for j in range(K,0,-1):
            #되도록이면 앞에 있는 걸 먹는게 나음
            if i-j >=1 and arr[i-j] == 'H' and not check[i-j]: #햄버거임 안 먹음
                check[i-j] = 1
                flag = False
                break
        if flag: #앞에 있는거 못먹으면    
            for j in range(1,K+1):
                #뒤에꺼 먹어야재..
                if i+j <=N and arr[i+j] == 'H' and not check[i+j]: #햄버거임 안 먹음
                    check[i+j] = 1
                    break  
print(sum(check))                  
                
            
