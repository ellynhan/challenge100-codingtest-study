# 백준 1463번 1로 만들기
# 실버 3
import sys

def find(n):
    if n in d.keys():
        return d[n]
    else:
        d[n] = min(find(n//3) + 1 + n%3, find(n//2) + 1 + n%2)
        return d[n]

N = int(sys.stdin.readline())
d = {1 : 0,
     2 : 1,
     3 : 1,
     4 : 2,
     5 : 3,
     6 : 2}

print(find(N))
