import sys

def fib() :
    num = [1, 0]
    def get_next_number() :
        nonlocal num
        num[0], num[1] = num[1], num[0] + num[1]
        return num
    return get_next_number

def fibonacci(n) :
    if n == 0 :
        return [1, 0]
    else :
        f = fib()
        for i in range(0, n) :
            num = f()
        return num

test_case_num = int(sys.stdin.readline())
for i in range(test_case_num) :
    test_case = int(sys.stdin.readline())
    num = fibonacci(test_case)
    print(f"{num[0]} {num[1]}")
