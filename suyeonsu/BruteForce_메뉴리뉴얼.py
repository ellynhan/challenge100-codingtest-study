from itertools import combinations

def solution(orders, course):
    answer = []
    
    for n in course:
        menu = dict()
        for o in orders:
            if len(o) >= n:
                for case in combinations(sorted(o), n):
                    if ''.join(case) not in menu: menu[''.join(case)] = 0
                    menu[''.join(case)] += 1
                    
        for k, v in menu.items():
            if v >= 2 and v == max(menu.values()): answer.append(k)
            
    answer.sort()
    return answer
  
"""
sort와 sorted의 차이

sorted()
- 새로운 정렬된 목록을 반환하며, 원래 목록은 영향을 받지 않음
- 문자열, 튜플, 딕셔너리, 제너레이터 등 모든 요소가 포함된 반복 가능한 객체를 정렬하여 반환

list.sort()
- list를 그 자리에서 정렬하고 목록 인덱스를 변경하고 None을 반환
- 복사본을 만들 필요가 없으므로 sorted()보다 빠름
"""
