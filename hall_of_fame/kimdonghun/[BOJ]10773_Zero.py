import sys

K = int(sys.stdin.readline())

s = []

for i in range(K):
    num = int(sys.stdin.readline())

    if num == 0:
        s.pop()
    else:
        s.append(num)

print(sum(s))
