import sys

def fact(end, to = 1):
    result = 1
    for i in range(to+1, end+1):
        result *= i
    return result

n = int(input())

for _ in range(n):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    print(fact(b,b-a) // fact(a))