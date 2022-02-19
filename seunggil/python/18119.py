import sys

class Word:
    def __init__(self) -> None:
        pass

n, m = map(int, sys.stdin.readline().rstrip().split())

alpha = [ [] for _ in range(26)]
words = [Word() for _ in range(n)]

for i in range(n):
    words[i].word = set(sys.stdin.readline().rstrip())
    words[i].total = len(words[i].word)
    words[i].now = words[i].total
    for c in words[i].word:
        alpha[ord(c)-97].append(words[i])

ans = n
for _ in range(m):
    type, a = sys.stdin.readline().rstrip().split()
    if type == '1':
        for w in alpha[ord(a)-97]:
            w.now -= 1
            if w.now == w.total - 1:
                ans -= 1
    else :
        for w in alpha[ord(a)-97]:
            w.now += 1
            if w.now == w.total:
                ans += 1

    sys.stdout.write(str(ans)+"\n")