import sys
input = sys.stdin.readline

n, m = map(int, input().split())
x = set(input() for _ in range(n)).intersection(set(input() for _ in range(m)))
print(len(x))
print(''.join(sorted(list(x))))
