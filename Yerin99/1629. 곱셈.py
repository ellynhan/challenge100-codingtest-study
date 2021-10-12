def calc(a, b, c):
    if b == 1:
        return a % c

    small_pow = calc(a, b//2, c)
    if b % 2 == 0:
        return small_pow ** 2 % c
    else:
        return small_pow ** 2 * a % c


A, B, C = map(int, input().split())
print(calc(A, B, C))
