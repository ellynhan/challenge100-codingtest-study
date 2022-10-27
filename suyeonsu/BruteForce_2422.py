from itertools import combinations

n, m = map(int, input().split())
dont_mix = {i:[] for i in range(1, n+1)}
for _ in range(m):
    a, b = map(int, input().split())
    dont_mix[a].append(b)
    dont_mix[b].append(a)

cnt = 0
for a, b, c in list(combinations(range(1, n+1), 3)):
    if a not in dont_mix[b] and a not in dont_mix[c] and b not in dont_mix[c]:
        cnt += 1
print(cnt)

"""

[주로 사용되는 완전탐색 기법들]

  1. 단순 Brute-Force
  2. 비트마스크(Bitmask)
  3. 재귀 함수
  4. 순열 (Permutation), 조합 (Combination)
  5. BFS / DFS
  
"""
