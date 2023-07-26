# https://programmers.co.kr/learn/courses/30/lessons/42627#
# 힙 개념 다시 확인할 것

import heapq
from collections import deque

def solution(jobs):
    jobs.sort(key=lambda x:x[0])
    q = deque(jobs)
    h = []
    time = 0
    answer = 0
    while q or h:
        while q and q[0][0] <= time:
            start, execution = q.popleft()
            heapq.heappush(h, (execution, start))
        if h:
            execution, start = heapq.heappop(h)
            time += execution
            # print(time-start)
            answer += time - start
            continue
        time+=1
        
    return answer//len(jobs)