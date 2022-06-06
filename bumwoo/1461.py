n, m = map(int, input().split())
books = list(map(int, input().split()))
p = [p for p in books if p > 0]
n = [-n for n in books if n < 0]

p.sort(reverse=True)
n.sort(reverse=True)

answer = 0

for i in range(0, len(p), m):
        answer += p[i] * 2

for i in range(0, len(n), m):
        answer += n[i] * 2

if p and n:
        if p[0] >= n[0]:
                answer -= p[0]
        else:
                answer -= n[0]
else:
        if not n:
                answer -= p[0]
        else:
                answer -= n[0]

print(answer)