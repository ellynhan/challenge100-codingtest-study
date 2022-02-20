a = [True]*10001
for i in range(2, 10001):
    if a[i]:
        for j in range(i + i, 10001, i):
            a[j] = False

t = int(input())
for i in range(t):
    n = int(input())
    small, big = 0, 0
    for j in range(2, n//2+1):
        if a[j] and a[n-j]:
            small = j
            big = n-j
    print(small, big)
