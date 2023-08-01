#https://programmers.co.kr/learn/courses/30/lessons/42628

import heapq
def solution(operations):
    min_h = []
    max_h = []
    for operation in operations:
        command, num = operation.split()
        num = int(num)
        if command == "D" and min_h:
            if num == 1:
                val = heapq.heappop(max_h)
                min_h.remove(-val)
            elif num == -1:
                val = heapq.heappop(min_h)
                max_h.remove(-val)
        elif command == "I":
            heapq.heappush(min_h, num)
            heapq.heappush(max_h, -num)
            

    return [0, 0] if len(min_h)==0 else [-heapq.heappop(max_h), heapq.heappop(min_h)]
