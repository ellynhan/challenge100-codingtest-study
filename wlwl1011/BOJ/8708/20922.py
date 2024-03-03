import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

N, K = map(int, input().split())
arr = list(map(int, input().split()))
max_value = max(arr)
counter = [0] * max_value

answer = 0
left, right = 0, 0

while right < N:
    if counter[arr[right]-1] < K:
        counter[arr[right]-1] += 1 
        right += 1
    else:
        counter[arr[left]-1] -=1
        left += 1
    answer = max(answer, right-left)

print(answer)            
