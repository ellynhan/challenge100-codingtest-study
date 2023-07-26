import sys

N = int(sys.stdin.readline())
stairs =[]

for i in range(N):
    stairs.append(int(sys.stdin.readline()))

d = [0] * len(stairs)
#print(stairs)

d[0] = stairs[0]

if N == 1:
    print(d[0])
elif N == 2:
    d[1] = stairs[0] + stairs[1]
    print(d[1])
else:
    d[1] = stairs[0] + stairs[1]
    d[2] = max(stairs[1], stairs[0]) + stairs[2]

    for i in range(3, len(stairs)):
        d[i] = max(d[i-2], d[i-3] + stairs[i-1]) + stairs[i]

    #print(stairs)
    #print(d)

    print(d[-1])
