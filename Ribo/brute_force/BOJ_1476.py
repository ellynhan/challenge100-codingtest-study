import sys
input = sys.stdin.readline

e, s, m = map(int, input().split())
a, b, c, year = 1, 1, 1, 1

while True:
    if a == e and b == s and c == m: break
    a += 1; b += 1; c += 1; year += 1
    if a > 15: a -= 15
    if b > 28: b -= 28
    if c > 19: c -= 19

print(year)
