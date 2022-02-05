import sys

N = list(sys.stdin.readline()[:-1])
#print(N)

N.sort(reverse=True)

for i in N:
    print(i, end = "")