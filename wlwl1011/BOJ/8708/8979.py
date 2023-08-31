import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, K = map(int, input().split())
arr = [[0,0,0,0] for _ in range(N)] #숫자, 금, 은, 동

for i in range(N):
    num, gold, silver, bronze = map(int, input().split())
    arr[i] = [num, gold,silver,bronze]

arr.sort(key=lambda x: (x[1],x[2],x[3]), reverse=True)
check = [0] * (N+1)
answer = 1
check[1] = 1
# print('...................')
# for i in range(N):
#     print(arr[i])

for i in range(1, N):
    
    if not (arr[i][1] == arr[i-1][1] and arr[i][2] == arr[i-1][2] and arr[i][3] == arr[i-1][3]):
        if arr[i][1] < arr[i-1][1]: #금메달 수가 더 적으면
            answer += check[answer]
        else: #금메달 수가 같으면
            #은메달 수가 더 적으면
            if arr[i][2] < arr[i-1][2]:
                answer += check[answer]
            else: #은메달 수가 같으면
                #동메달 수가 더 적으면
                if arr[i][3] < arr[i-1][3]:
                    answer += check[answer]
                else:
                    #동메달 수가 같으면
                    continue     
    if arr[i][0] == K:
        break  
    check[answer] += 1    
    #print(check)    
print(answer)