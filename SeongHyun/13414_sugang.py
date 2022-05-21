import sys
import heapq

students = dict()
heap = []
sugang_len, input_len = map(int, input().split())

for i in range(input_len):
    student = sys.stdin.readline().strip()
    students[student] = i

for k, v in students.items():
    heapq.heappush(heap, (v, k))

for _ in range(sugang_len):
    print(heapq.heappop(heap)[1])
    if not heap:
        break
