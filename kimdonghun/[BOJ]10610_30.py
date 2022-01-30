import sys

N = list(sys.stdin.readline()[:-1])

N.sort(reverse=True)
sorted_N = int(''.join(N))

if sorted_N % 30 == 0:
    print(sorted_N)
else:
    print(-1)
