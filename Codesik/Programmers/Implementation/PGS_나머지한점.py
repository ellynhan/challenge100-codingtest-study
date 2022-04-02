from collections import defaultdict


def solution(v_arr):
    answer = []
    cnt_dict_x = defaultdict(int)
    cnt_dict_y = defaultdict(int)

    for v in v_arr:
        cnt_dict_x[v[0]] += 1
        cnt_dict_y[v[1]] += 1

    print(cnt_dict_x, cnt_dict_y)
    for v, cnt in cnt_dict_x.items():
        if cnt == 1:
            answer.append(v)
    for v, cnt in cnt_dict_y.items():
        if cnt == 1:
            answer.append(v)

    return answer
