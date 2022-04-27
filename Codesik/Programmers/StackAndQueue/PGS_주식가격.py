from collections import deque

def solution(prices):
    answer = []
    prices = deque(prices)
    while True:
        if not prices:
            break
        target = prices.popleft()
        sec = 0
        for p in prices:
            sec += 1
            if p < target:
                break
        answer.append(sec)
    return answer