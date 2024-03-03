import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from itertools import combinations

N, M = map(int, input().split())
arr = [i for i in range(1,N+1)]
ans = []
for temp in combinations(arr,M):
    print(temp)
#     temp = list(temp)
#     temp.sort()
#     ans.append(temp)

# ans.sort()

# for i in range(len(ans)):
#     print(*ans[i])

