from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for c in course:
        menu = []
        for order in orders:
            # combinations 함수는 문자열 순서도 따지기 때문에 order를 미리 정렬해야함
            comb = combinations(sorted(order), c)
            menu += comb
        counter = Counter(menu)
        # 최소 2명 이상의 손님이 주문한 조합
        if counter and max(counter.values()) != 1:
            for m, cnt in counter.items():
                if cnt == max(counter.values()):
                    answer.append(''.join(m))
    return sorted(answer)