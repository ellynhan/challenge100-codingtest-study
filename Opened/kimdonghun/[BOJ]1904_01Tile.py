import sys
d = [1,2]

def tile(n):
    length = len(d)
    if n >= length:
        for i in range(length, n):
            d.append((d[i-1] + d[i-2]) % 15746)

N = int(sys.stdin.readline())
tile(N)
#print(d)
print(d[N-1])
