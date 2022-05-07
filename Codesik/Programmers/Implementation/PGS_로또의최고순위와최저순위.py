def solution(lottos, win_nums):
    answer = []

    score_dict = {
        6: 1,
        5: 2,
        4: 3,
        3: 4,
        2: 5,
        1: 6
    }

    # 0을 제거
    num_of_zero = 0
    while True:
        try:
            lottos.remove(0)
            num_of_zero += 1
        except Exception:
            break
    # 맞는 번호 세기
    num_of_collect = 0
    complement = list(set(lottos) & set(win_nums))
    num_of_collect += len(complement)
    print(num_of_zero, complement)

    if not num_of_collect and not num_of_zero:
        return [6, 6]

    answer.append(
        score_dict[num_of_collect + num_of_zero] if num_of_collect + num_of_zero != 0 else 6
    )
    answer.append(
        score_dict[num_of_collect] if num_of_collect != 0 else 6
    )
    return answer