import math
def solution(begin, end):
    answer = []
    for i in range(begin, end+1):
        if i < 2:
            answer.append(0)
            continue
        for j in range(2, int(math.sqrt(i))+1):
            if i % j == 0 and i // j <= 10000000:
                answer.append(i // j)
                break
        else:
            answer.append(1)
        
    return answer