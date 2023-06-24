from collections import defaultdict

n = int(input())
d = defaultdict(int)
for _ in range(n):
    d[input()] += 1
print(sorted([(-v, k) for k, v in d.items()])[0][1])
