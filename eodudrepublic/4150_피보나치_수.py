import sys

def fib():
    x1 = 0
    x2 = 1
    def get_next_number():
        nonlocal x1, x2
        x3 = x1 + x2
        x1, x2 = x2, x3
        return x3
    return get_next_number

def fib_closure(n):
    f = fib()
    for i in range(2, n+1):
        num = f()
    return num

n = int(sys.stdin.readline())
if n == 0 :
    print(0)
elif n == 1 or n == 2 :
    print(1)
elif n > 2 :
    print(fib_closure(n))
