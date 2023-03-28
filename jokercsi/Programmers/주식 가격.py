"""
초 단위 주식 가격
가격이 떨어 지지 않은 기간은 몇 초 인지 구하기
"""


def solution(prices):
    answer = []
    queue = []
    
    for i in range(len(prices)):
        queue.append(prices[i]) 
        answer.append(0)
        
        for j in range(i+1, len(prices)):
            answer[i] += 1
            
            if prices[j] < prices[i]:
                break

    return answer
