import sys
import math
input = sys.stdin.readline


n = int(input())
examinee = list(map(int, input().split()))
b, c = map(int, input().split())

cnt = 0
for rest in examinee:
    rest -= b
    if rest <= 0:
        cnt += 1
    else:
        cnt += 1
        cnt += math.ceil(rest/c)

print(cnt)
