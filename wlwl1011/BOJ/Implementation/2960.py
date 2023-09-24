import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import deque

N, K = map(int, input().split())

arr = deque([i for i in range(2, N+1)])

def checkPrim(n):
    for i in range(2,n):
        if n%i == 0:
            return False
    return True     

cnt = 0
while arr:
    if checkPrim(arr[0]):
        P = arr.popleft()
        cnt += 1
        if cnt == K:
            print(P)
            break
        i=2
        flag = True
        while P*i <= N:
            if P*i in arr:
                arr.remove(P*i)
                cnt += 1
                if cnt == K:
                    print(P*i)
                    flag = False
                    break
            i +=1
        if flag == False:
            break    


#다른 사람 풀이
# nums = [True] * (N+1)

# for i in range(2, len(nums) + 1):
#     for j in range(i, N+1, i):
#         if nums[j] == True:
#             nums[j] = False
#             cnt += 1
#             if cnt == K:
#                 print(j)
#                 break