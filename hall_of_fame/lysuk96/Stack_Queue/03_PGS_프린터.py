#프린터
from collections import deque
def solution(priorities, location):

    Q = deque([i for i in range(len(priorities))])
    
    answer = 1
    while Q :
        if max(priorities) != priorities[Q[0]]:
            Q.append(Q.popleft())
        else:
            if Q[0] == location:
                break
            priorities[Q[0]] = -1
            Q.popleft()
            answer+=1

    return answer

print(solution([1, 1, 9, 1, 1, 1],0))

# 다른 사람 풀이
# def solution(priorities, location):
#     queue =  [(i,p) for i,p in enumerate(priorities)]
#     answer = 0
#     while True:
#         cur = queue.pop(0)
#         if any(cur[1] < q[1] for q in queue):
#             queue.append(cur)
#         else:
#             answer += 1
#             if cur[0] == location:
#                 return answer