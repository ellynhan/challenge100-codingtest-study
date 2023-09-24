def solution(a, b, g, s, w, t):
    start = 0
    # 최악의 경우
    # 광물의 최대무게 : 10**9 * 2(금,은)
    # 도시가 1개만 있고 소요시간이 최대, 1씩 옮길 수 있을 때 : 10**5 * 2(왕복)
    answer = end = (10 ** 9) * (10 ** 5) * 4

    # 이진 탐색
    while start <= end:
        mid = (start + end) // 2
        gold = 0
        silver = 0
        total = 0

        for i in range(len(g)):
            # 현재 정보
            now_gold = g[i]
            now_silver = s[i]
            now_weight = w[i]
            now_time = t[i]

            # 주어진 시간내에서 이동할 수 있는 횟수 (왕복으로 계산)
            move_cnt = mid // (now_time * 2)

            # 편도 추가
            if mid % (now_time * 2) >= now_time:
                move_cnt += 1

            # 주어지 시간 내 최대 적재 가능량 누적하기
            possible_move_weight = move_cnt * now_weight
            gold += now_gold if (now_gold < possible_move_weight) else possible_move_weight
            silver += now_silver if (now_silver < possible_move_weight) else possible_move_weight
            total += now_gold + now_silver if (now_gold + now_silver < possible_move_weight) else possible_move_weight

        # total이 a+b 보다 크거나 같으면서 금과 은의 누적 최대값이 a와 b보다 크거나 같아야 한다.
        # 만약 금과 은의 누적 최대값이 보내야만 하는 a,b보다 작다면 현재 시간 내 처리 불가능하다.
        if total >= a + b and gold >= a and silver >= b:
            end = mid - 1
            answer = min(answer, mid)
        else:
            start = mid + 1
    return answer