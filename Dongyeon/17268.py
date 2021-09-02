# 백준 17268번 미팅의 저주
# 골드 3
import sys
N = int(sys.stdin.readline())
d = {0 : 1,
     2 : 1,
     4 : 2,
     6 : 5,
     8 : 14}

for i in range(0, N+2, 2):
    if i not in d.keys():
        count = 0
        for a in range(0, i, 2):
            count += d[a]*d[i-a-2]
        d[i] = count % 987654321
print(d[N] % 987654321)

