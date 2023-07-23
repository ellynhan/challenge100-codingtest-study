fib = [(1, 0), (0, 1)]
for _ in range(2, 41):
    fib.append((fib[-1][0]+fib[-2][0], fib[-1][1]+fib[-2][1]))
for _ in range(int(input())):
    print(*fib[int(input())])
