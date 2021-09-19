# 백준 9095번 1, 2, 3 더하기
# 실버 3
import sys
from math import factorial as fac

def comb(n, i, j):
    k = n-3*i-2*j
    m = i + j + k
    return int(fac(m)/(fac(i)*fac(j)*fac(k)))

T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    count = 0
    for i in range(n//3+1):
        for j in range(n//2+1):
            if 3*i+ 2*j <= n:
                add = comb(n, i, j)
                count += add
    print(count)
