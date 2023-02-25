from collections import deque
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
v = list(map(int, input().split()))
calc = lambda i, j:(j-i) * (1 + abs(v[i]-v[j]))
visited = [0] * n

dq = deque([0])
while dq:
    i = dq.popleft()
    for j in range(i+1, n):
        if calc(i, j) <= k and not visited[j]:
            visited[j] = 1
            if j == n-1:
                print('YES')
                exit(0)
            dq.append(j)
print('NO')

# 항상 탐색 수행시 불필요한 부분(이미 수행했던)을 탐색하고 있지 않은지 점검
