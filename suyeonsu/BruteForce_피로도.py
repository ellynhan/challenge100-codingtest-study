from itertools import permutations

def solution(k, dungeons):
    answer = 0
    for p in permutations(dungeons, len(dungeons)):
        cnt = 0
        now = k
        for required, v in p:
            if now >= required:
                now -= v
                cnt += 1
        answer = max(answer, cnt)
    return answer
