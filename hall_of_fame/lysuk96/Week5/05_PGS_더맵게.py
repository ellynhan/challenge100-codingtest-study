#https://programmers.co.kr/learn/courses/30/lessons/42626

import heapq
def solution(scoville, K):
    h = []
    heapq.heapify(scoville)
    answer = 0
    while scoville[0] < K and len(scoville)>1:
        worst = heapq.heappop(scoville)
        worse = heapq.heappop(scoville)
        new = worst + (2*worse)
        heapq.heappush(scoville, new)
        answer+=1
    return -1 if scoville[0] < K else answer