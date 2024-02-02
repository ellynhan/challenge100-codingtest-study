def solution(want, number, discount):
    
    want_dict = {}
    for i in range(len(want)):
        want_dict[want[i]] = number[i]
    
    days = 0 # 할인받을 수 있는 회원 등록 날짜
    
    for i in range(len(discount)-9):
        discount_10day={} # 10일간 할인받을 수 있는 제품명과 수량을 딕셔너리로 저장
        for j in range(i,i+10):
            discount_10day[discount[j]] = discount_10day.get(discount[j],0) + 1
        # 딕셔너리의 ==연산은 key와 value값이 모두 같을 때 
        if want_dict == discount_10day:
            days += 1
    return days

"""
할인받을 수 있는 제품들의 딕셔너리를 하나씩 선언해서 추가하지 않고,
collections 모듈의 Counter를 사용해서 바로 만들 수 있음.
"""

from collections import Counter
def solution(want, number, discount):
    answer = 0
    dic = {}
    for i in range(len(want)):
        dic[want[i]] = number[i]

    for i in range(len(discount)-9):
        if dic == Counter(discount[i:i+10]): 
            answer += 1

    return answer