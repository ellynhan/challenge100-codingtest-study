n = int(input())


def hanoi(n, a, b, c):
    if n == 1:
        print(a, c)
        return
    hanoi(n - 1, a, c, b)
    print(a, c)
    hanoi(n - 1, b, a, c)


sum_val = (2 ** n) - 1
print(sum_val)

hanoi(n, 1, 2, 3)
