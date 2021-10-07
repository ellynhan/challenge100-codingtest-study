# 8 50 23분
import sys
from collections import *


def solution(scores):
    score_list = defaultdict(list)
    result = []
    for i in range(len(scores)):
        for score in scores:
            score_list[i].append(score[i])

    for student, score in score_list.items():
        my_score = score[student]

        max_value = max(score)
        max_value_list = [i for i, v in enumerate(score) if v == max_value]

        min_value = min(score)
        min_value_list = [i for i, v in enumerate(score) if v == min_value]


        if my_score == max_value and len(max_value_list) == 1:
            sum_score = sum(score) - my_score
            sum_score /= len(score) - 1
        elif my_score == min_value and len(min_value_list) == 1:
            sum_score = sum(score) - my_score
            sum_score /= len(score) - 1
        else:
            sum_score = sum(score)
            sum_score /= len(score)
        result.append(sum_score)

    answer = ''

    for score in result:
        if score >= 90:
            answer += 'A'
        elif 80 <= score < 90:
            answer += 'B'
        elif 70 <= score < 80:
            answer += 'C'
        elif 50 <= score < 70:
            answer += 'D'
        elif score < 50:
            answer += 'F'
    return answer