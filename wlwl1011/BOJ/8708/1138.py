
import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


N = int(input())
arr = list(map(int, input().split()))
answer = [0] * N

for i in range(N-1,-1,-1):
    check = arr[i]
    check_idx = 0
    idx = 0
    
    for j in answer:
        if check == check_idx:
            break
        if j > (i+1):
            check_idx += 1
        idx += 1   
    #print(answer,idx)    
    if idx >= N:
        answer[answer.index(0)] = i+1

    elif answer[idx] != 0:
        answer.insert(idx,i+1)
        answer.pop(answer.index(0))
    else:
        answer[idx] = (i+1)    
print(*answer)