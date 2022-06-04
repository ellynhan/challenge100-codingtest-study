import heapq

def solution(scoville, K):
    heap = []

    for s in scoville:
        heapq.heappush(heap, s)

    if heap[0] >= K:
        return 0

    cnt = 0
    while True:
        if len(heap) == 2:
            f = heapq.heappop(heap)
            s = heapq.heappop(heap)

            if (f + s*2) >= K:
                return cnt + 1
            else:
                return -1
        else:
            f = heapq.heappop(heap)
            s = heapq.heappop(heap)

            if heap[0] >= K and (f + s*2) >= K:
                return cnt + 1

            heapq.heappush(heap, (f + s*2))
            cnt += 1