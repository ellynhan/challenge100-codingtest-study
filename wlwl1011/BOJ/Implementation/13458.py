import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
import math
N = int(input()) #시험장 개수
arr = list(map(int, input().split()))

B, C = map(int, input().split())
answer = 0
for i in range(N):
    arr[i] -= B
    answer += 1
    if arr[i] < 0:
        arr[i] = 0
    else:
        answer += math.ceil(arr[i] / C )

print(answer)