import sys, os, atexit, io
input = lambda : sys.stdin.readline().rstrip('\n\r')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))


N = int(input())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

dx = [-1,1,0,0]
dy = [0,0,-1,1]
ans = 0
for i in range(N):
    for j in range(N):
        cnt = 0
        for d in range(4):
            tx = i + dx[d]
            ty = j + dy[d]

            if 0 <= tx < N and 0 <= ty < N:
                if arr[tx][ty]:
                    cnt += 1
        if cnt >= 3:
            ans += 1        
          
print(ans)            