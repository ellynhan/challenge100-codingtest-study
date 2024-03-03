import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
 
def check(data):
    max_cnt = 1
    for i in range(N):
        cnt = 1
        for j in range(1,N):
            if data[i][j] == data[i][j-1]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(max_cnt, cnt)
        cnt = 1
        for j in range(1,N):
            if data[j][i] == data[j-1][i]:
                cnt += 1
            else:
                cnt = 1
            max_cnt = max(max_cnt, cnt)
    return max_cnt                           


N = int(input())
data = []

for _ in range(N):
    data.append(list(input()))

ans = 0

for i in range(N):
    for j in range(N):
        if j + 1 < N:
            data[i][j], data[i][j+1] = data[i][j+1], data[i][j]
            cnt = check(data)
            ans = max(ans, cnt)
            data[i][j], data[i][j+1] = data[i][j+1], data[i][j]
        if i + 1 < N:
            data[i][j], data[i+1][j] = data[i+1][j], data[i][j]
            cnt = check(data)
            ans = max(ans, cnt)
            data[i][j], data[i+1][j] = data[i+1][j], data[i][j]
            
print(ans)


