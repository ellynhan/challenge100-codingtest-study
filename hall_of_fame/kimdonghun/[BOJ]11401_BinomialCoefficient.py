import sys

N, K = map(int, sys.stdin.readline().split())
P = 1000000007

def my_pow(a, b):
    if b == 1:
        return a % P
    
    tmp_res = my_pow(a, b // 2)

    if b % 2 == 0:
        return tmp_res * tmp_res % P
    else:
        return tmp_res * tmp_res * a % P

A = 1
# n!
for i in range(1, N+1):
    A *= i
    A %= P

B = 1
# k!(n-k)!
for i in range(1, K+1):
    B *= i
    B %= P
for i in range(1, N-K+1):
    B *= i
    B %= P

res = A * my_pow(B, P-2) % P
print(res)
