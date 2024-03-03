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

#국가 K에 해당하는 index 찾기
idx = [arr[i][0] for i in range(N)].index(K)

for i in range(N):
    if arr[idx][1:] == arr[i][1:]:
        print(i+1)
        break