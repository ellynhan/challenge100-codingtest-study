from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []

    for cnt in course:
        ordered_com = []

        for order in orders:
            ordered_com.extend(combinations(sorted(order), cnt))

        cnt_order_com = Counter(ordered_com).most_common()
        answer.extend(
            ["".join(order) for order, cnt in cnt_order_com if cnt >= cnt_order_com[0][1] > 1]
        )

    return sorted(answer)