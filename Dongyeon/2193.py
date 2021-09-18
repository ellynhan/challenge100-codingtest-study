N = int(input())

def fib(n, d):
    if n in d.keys():
        return d[n]
    else:
        d[n] = fib(n-1, d) + fib(n-2, d)
        return d[n]

d = {1 : 1,
     2 : 1,
     3 : 2}

print(fib(N, d))
