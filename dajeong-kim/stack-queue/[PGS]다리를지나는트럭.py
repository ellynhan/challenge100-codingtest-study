from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0 # 걸린 시간

    # bridge : 다리를 지나는 트럭
    bridge = deque([0]*bridge_length)
    truck_weights = deque(truck_weights)
    cur_weight = 0

    while truck_weights:
        answer += 1
        cur_weight -= bridge.popleft() 
        # sum 함수를 사용하지 않고 cur_weight를 통해 미리 계산해줘야 시간 초과 안뜸

        if cur_weight + truck_weights[0] <= weight:
            truck = truck_weights.popleft()
            cur_weight += truck
            bridge.append(truck)
        else:
            bridge.append(0)
    
    #마지막으로 다리에 들어간 트럭이 나올때까지의 시간 더하기
    answer += bridge_length

    return answer