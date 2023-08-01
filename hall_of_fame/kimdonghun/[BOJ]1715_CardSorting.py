import sys
import heapq

N = int(sys.stdin.readline())
card = []

for i in range(N):
    card.append(int(sys.stdin.readline()))

card.sort()

pq = []
for c in card:
    pq.append(c)

sum = 0
cmp_cnt = 0
while len(pq) > 1:
    sum = heapq.heappop(pq) + heapq.heappop(pq)
    cmp_cnt += sum
    pq.append(sum)

print(cmp_cnt)
