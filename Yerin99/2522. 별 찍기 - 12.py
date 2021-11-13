n = int(input())
for i in range(1, 2*n):
    k = abs(n-i)
    print(" "*k + "*"*(n-k))
