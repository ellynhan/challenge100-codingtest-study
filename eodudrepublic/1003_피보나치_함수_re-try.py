import sys

def fib():
    a = 0
    b = 1
    def get_next_number():
        nonlocal a, b
        a, b = b, a + b
        return b
    return get_next_number

def fibonacci(n):
    if n == -1 :
        return 1
    elif n == 0 :
        return 0
    elif n == 1 :
        return 1
    else :
        f = fib()
        for i in range(2, n+1):
            num = f()
        return num

test_case_num = int(sys.stdin.readline())
for i in range(test_case_num) :
    test_case = int(sys.stdin.readline())
    print(f"{fibonacci(test_case-1)} {fibonacci(test_case)}")
