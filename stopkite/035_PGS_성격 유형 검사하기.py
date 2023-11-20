def compare_score(dic, a, b):
    if dic[a] > dic[b]:
        return a
    elif dic[a] < dic[b]:
        return b
    else:
        if ord(a) - ord(b) > 0:
            return b
        else:
            return a


def solution(survey, choices):
    answer = ''

    # 1. 성격 유형 dict 선언
    character_dict = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    # 2. 성격 점수 dict 선언
    score_dict = {1: 3, 2: 2, 3: 1, 4: 0, 5: 1, 6: 2, 7: 3}

    # 3. 점수 판단
    n = len(survey)
    for i in range(n):
        c1, c2 = survey[i][0], survey[i][1]
        choice = choices[i]

        # 4. 점수 누적
        if choice < 4:
            character_dict[c1] += score_dict[choice]
        elif choice > 4:
            character_dict[c2] += score_dict[choice]

    # 5. 누적 점수 비교
    answer += compare_score(character_dict, 'R', 'T')
    answer += compare_score(character_dict, 'C', 'F')
    answer += compare_score(character_dict, 'J', 'M')
    answer += compare_score(character_dict, 'A', 'N')

    return answer
