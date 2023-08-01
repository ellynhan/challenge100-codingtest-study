import sys

S = int(sys.stdin.readline()[:-1])

N = 0
num = 1
tot = 0

while tot < S:
    tot += num

    if tot > S:
        break

    N += 1
    #print(N, num)

    num += 1

print(N)
