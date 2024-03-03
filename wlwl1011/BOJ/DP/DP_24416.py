import sys, io, os, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

global count1 
global count2

def fib(n):
    global count1
    if n == 1 or n == 2:
        count1 += 1
        return 1;  # 코드1
    else:
        return (fib(n - 1) + fib(n - 2))

def fibonacci(n):
    global count2
    
    f= [0] * (n+1)
    f[1] =  1
    f[2] = 2
    for i in range( 3, n+1 ) :
        count2 += 1
        f[i] = f[i - 1] + f[i - 2] # 코드2
    return f[n]

count1 = 0
count2 = 0

n = int(input())
fib(n)
fibonacci(n)
print(count1, count2)