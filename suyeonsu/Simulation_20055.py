from collections import deque
import sys

n, k = map(int, input().split())
belt = deque(map(int, input().split()))
robot = deque([0] * n)

step = 1
while True:
    # 1
    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0

    # 2
    for i in range(n-2, -1, -1):
        if robot[i] and not robot[i+1] and belt[i+1]:
            robot[i] = 0
            robot[i+1] = 1
            belt[i+1] -= 1
    robot[-1] = 0

    # 3
    if belt[0]:
        robot[0] = 1
        belt[0] -= 1
    
    # 4
    if belt.count(0) >= k: break
    else: step += 1

print(step)

"""
[구현]
머릿속에 있는 알고리즘을 소스코드로 바꾸는 과정
풀이를 떠올리는 것은 쉽지만 소스코드로 옮기기 어려운 문제
  - 완전탐색: 모든 경우의 수를 주저 없이 다 계산하는 해결 방법
  - 시뮬레이션: 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행해야하는 문제 유형
"""
