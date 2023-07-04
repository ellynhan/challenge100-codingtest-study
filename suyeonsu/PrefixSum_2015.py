from collections import defaultdict

n, k = map(int, input().split())
a = list(map(int, input().split()))
prefix = defaultdict(int)
prefix[0] = 1
s = 0
answer = 0
for i in a:
    s += i
    if s-k in prefix.keys():
        answer += prefix[s-k]
    prefix[s] += 1
print(answer)
