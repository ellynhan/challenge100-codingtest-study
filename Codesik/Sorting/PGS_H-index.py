# 11 07 11:44 37분 걸림
def solution(citations):
    answer = 0
    citations.sort()

    is_found = True
    for n in range(0, citations[-1]):
        if not is_found:
            break
        is_found = False

        for i, h in enumerate(citations):
            if n <= h:
                left_c = citations[0:i]
                right_c = citations[i:]
                if n <= len(right_c) and len(left_c) <= n:
                    is_found = True
                    answer = n
                    break

    return answer