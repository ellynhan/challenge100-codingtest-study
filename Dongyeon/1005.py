# 백준 1005번 ACM Craft
# 골드 3
import sys

def find_indices(l, k): # 리스트, key list 값을 받아서 해당하는 index를 return 하는 함수
    tmp = []
    for i, v in enumerate(l):
        if v in k:
            tmp.append(i)
    return tmp


T = int(sys.stdin.readline())
for _ in range(T):
    N, K = map(int, sys.stdin.readline().strip().split())
    time = list(map(int, sys.stdin.readline().strip().split()))
    f = []
    l = []
    for _ in range(K):
        a, b = map(int, sys.stdin.readline().strip().split())
        f.append(a)
        l.append(b)
    W = int(sys.stdin.readline())
    ness = [[W]]
    while True:
        tmp = find_indices(l, ness[-1])
        if tmp == []:
            break
        ness.append([f[t] for t in tmp])
    ness.reverse()
    already = []
    for k, ls in enumerate(ness):
        ness[k] = [e for e in ls if e not in already]
        already.extend(ness[k])
    count = 0
    for q, lis in enumerate(ness):
        count += max([time[v-1] for v in lis])
    print(count)
