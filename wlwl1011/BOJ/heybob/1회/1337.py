import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = []

for _ in range(N):
    arr.append(int(input()))

arr.sort()

cnt, ans = 0, 0
start = 0

for end in range(len(arr)):
    cnt += 1

    while arr[end]-arr[start] > 4:
        start += 1
        cnt -=1
    ans = max(cnt, ans)

if ans > 5:
    ans = 5
print(5-ans)            