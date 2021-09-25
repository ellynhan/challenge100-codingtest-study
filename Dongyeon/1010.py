# 백준 1010번 다리놓기
# 실버 5

import sys

def factorial(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        return n*factorial(n-1)



T = int(sys.stdin.readline())

for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    print(int(factorial(b)/(factorial(a)*factorial(b-a))))
