"""
시소 2, 3, 4
무게 상쇄 : 짝꿍 
짝궁이 몇 쌍 존재 하는지 구하기
"""
from collections import Counter # 무게의 종류는 901가지

def solution(weights):
    answer = 0
    times = (3/4, 2/3, 1/2)  # 0.75배, 0.333배, 0.5배 
    count_dict = Counter(weights)
    
    # 같은 무게일 경우
    for key, value in count_dict.items():
        # same value  = 2, 3, 4,  5,  6,  7
        # combination = 1, 3, 6, 10, 15, 21 
        if value > 1:
            answer += value * (value - 1) / 2
            
    
    # weights 안에 중복 없애기 
    weights = list(set(weights))
    
    # 같은 무게가 아닐 경우
    for i in weights:    
        for j in times:
            if i * j in weights:
                combination_num = count_dict[i * j] # 조합 갯수
                print(combination_num)
                answer += combination_num * count_dict[i]
            
    return answer
