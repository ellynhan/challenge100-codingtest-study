# 백준 1904번 01타일
# 실버 3

import sys
d = {1 : 1,
     2 : 2,
     3 : 3,
     4 : 5}

N = int(sys.stdin.readline())

for i in range(4, N+1):
    d[i] = (d[i-1] + d[i-2]) % 15746

print(d[N])
