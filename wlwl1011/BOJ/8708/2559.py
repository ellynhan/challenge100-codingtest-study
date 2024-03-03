import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#범위가 - 까지 간다는 것을 확인할것,
#누적합 연산시 0번 index를 만들어줄 것
#0을 만들어줬으니, For 문 작성시 유의 N+1 !!!
N, K = map(int, input().split())
arr = [0] + list(map(int, input().split()))

arr_cumulative = [0] * (N+1)

for i in range(1,N+1):
    arr_cumulative[i] += arr_cumulative[i-1] + arr[i] #누적합

max_val = -int(1e9)
for i in range(K,N+1):

    max_val = max(max_val, arr_cumulative[i]-arr_cumulative[i-K])

print(max_val)    