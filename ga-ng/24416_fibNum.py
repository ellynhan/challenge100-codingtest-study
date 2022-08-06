n = int(input())
cnt2 = 1

def fib(n):
    global cnt2
    
    if n == 1 or n == 2:
        return 1
    else:
        cnt2 += 1
        return fib(n-1) + fib(n-2)
    
def fibonacci(n):
    # f = [0]*41
    # f[1], f[2] = 1, 1
    
    cnt = 0
    for i in range(3,n+1):
        # f[i] = f[i-1] + f[i-2]
        cnt += 1
    
    return cnt


fib(n)
print(cnt2, fibonacci(n))