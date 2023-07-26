#다리를 지나는 트럭
#1트 : sum 이 O(N)이어서 테케 5번 시간초과 실패 -> 즉각반영 O(1)로 바꿔줌

from collections import deque
def solution(bridge_length, weight, truck_weights):
    Q = deque(truck_weights)
    time = 1
    bridge=deque([0] * bridge_length)
    bridge_sum = 0
    while Q :
        tmp = Q[0]
        if bridge[-1]==0 and\
            bridge_sum + tmp <= weight:
            bridge[-1] = Q.popleft()
            bridge_sum+=bridge[-1]
        else:
            bridge_sum -= bridge.popleft()
            bridge.append(0)
            time+=1
        # print(time, bridge, Q)
    
    return time + len(bridge)

print(solution(100	,100,	[10]))