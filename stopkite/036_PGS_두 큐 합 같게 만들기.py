from collections import deque


def solution(queue1, queue2):
    answer = 0
    q1, q2 = deque(queue1), deque(queue2)
    s1, s2 = sum(q1), sum(q2)

    while s1 != s2:
        if answer == 300000:
            answer = -1
            break
        if s1 > s2:
            temp = q1.popleft()
            q2.append(temp)
            s2 += temp
            s1 -= temp
        else:
            temp = q2.popleft()
            q1.append(temp)
            s1 += temp
            s2 -= temp
        answer += 1

    return answer