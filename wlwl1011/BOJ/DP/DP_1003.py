import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

global count_0, count_1


def fibonacci(n) :
    global count_0, count_1
    if n == 0:
        count_0 += 1
        return 0
    elif n == 1 :
        count_1 += 1
        return 1
    else :
        return fibonacci(n-1) + fibonacci(n-2)


T = int(input())

for _ in range(T):
    n = int(input())
    count_0 = 0
    count_1 = 0
    fibonacci(n)
    print(count_0,count_1)