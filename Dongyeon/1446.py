# 백준 1446번 지름길
# 실버 1

N, length = map(int, input().split())
shortcut = [list(map(int, input().split())) for _ in range(N)]

highway = [i for i in range(length+1)]

for i in range(length+1):
    if i > 0:
        highway[i] = min(highway[i], highway[i-1]+1)
    for s, e, d in shortcut:
        if i == s and e<=length and highway[i]+d < highway[e]:
            highway[e] = highway[i]+d

print(highway[-1])
