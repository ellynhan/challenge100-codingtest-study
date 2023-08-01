import sys

T = int(sys.stdin.readline())

for i in range(T):
    d = [1, 1, 1, 2, 2]
    N = int(sys.stdin.readline())

    if N <= 5:
        print(d[N-1])
    else:
        N -= 6
        for i in range(N+1):
            length = len(d)
            d.append(d[i] + d[length - 1])

        print(d[-1])
