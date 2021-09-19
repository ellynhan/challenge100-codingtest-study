# 백준 15989번 1, 2, 3 더하기 4
#  실버 1

T = int(input())
for _ in range(T):
    n = int(input())
    num_3 = n // 3
    count = 0
    for i in range(num_3 + 1):
        count += (n - 3*i) // 2 + 1
    print(count)
