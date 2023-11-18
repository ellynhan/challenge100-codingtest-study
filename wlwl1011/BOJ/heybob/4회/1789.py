import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
s = 0
idx = 0
while s <= N:
    idx += 1
    s += idx

print(idx-1)