from collections import deque

def solution(queue1, queue2):
    q1, q2 = deque(queue1), deque(queue2)
    s1, s2 = sum(q1), sum(q2)
    n = len(q1) * 2 + 10
    
    answer = 0
    while answer < n and s1 != s2:
        if s1 > s2:
            q2.append(q1.popleft())
            s1 -= q2[-1]
            s2 += q2[-1]
        else:
            q1.append(q2.popleft())
            s2 -= q1[-1]
            s1 += q1[-1]
        answer += 1
        
    return answer if answer < n else -1

"""
반복문 안에서 무의식적을 sum(), len() 등을 쓰지 않을 것
"""
