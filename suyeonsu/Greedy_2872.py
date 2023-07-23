import sys
input = sys.stdin.readline

n = int(input())
a = [int(input()) for _ in range(n)]
idx = n
answer = 0
for i in range(n-1, -1, -1):
    if a[i] != idx:
        answer += 1
    else:
        idx -= 1
print(answer)
