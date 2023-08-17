import sys
from collections import deque


def ans(s_a, s_b, s_c):
    if 'C' in s_a or 'B' in s_a:
        return False
    elif 'A' in s_b or 'C' in s_b:
        return False
    elif 'A' in s_c or 'B' in s_c:
        return False
    return True


def sol():
    stack = [sys.stdin.readline().strip()[2:] for _ in range(3)]
    #print(stack)
    check = set()
    dq = deque()
    dq.append([*stack, 0])
    while dq:
        print(dq)
        s_a, s_b, s_c, cnt = dq.popleft()
        if ans(s_a, s_b, s_c):      # 정답인지 확인
            return cnt
        else:
            temp = s_a + '.' + s_b + '.' + s_c      # 방문 표시를 위한 스트링
            if temp not in check:
                check.add(temp)     # 방문 표시
                # 아래는 전부 하나하나씩 큐에 집어넣는 과정
                if len(s_a) != 0:
                    dq.append((s_a[:-1], s_b + s_a[-1], s_c, cnt + 1))
                    dq.append((s_a[:-1], s_b, s_c + s_a[-1], cnt + 1))
                if len(s_b) != 0:
                    dq.append((s_a, s_b[:-1], s_c + s_b[-1], cnt + 1))
                    dq.append((s_a + s_b[-1], s_b[:-1], s_c, cnt + 1))
                if len(s_c) != 0:
                    dq.append((s_a, s_b + s_c[-1], s_c[:-1], cnt + 1))
                    dq.append((s_a + s_c[-1], s_b, s_c[:-1], cnt + 1))


print(sol())