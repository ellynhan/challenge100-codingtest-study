import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

S = int(input())

cnt = 0
sum = 0
while True:
    cnt += 1
    sum += cnt
    if sum > S:
        break
print(cnt-1)    