from itertools import combinations_with_replacement as combi

def solution(n, apeach):
    answer = [-1]
    max_gap = -1
    
    for idxs in combi(range(11), n):
        ryan = [0] * 11
        for i in idxs: ryan[10-i] += 1
            
        r, a = 0, 0
        for i in range(11):
            if ryan[i] == apeach[i] == 0: continue
            elif ryan[i] > apeach[i]: r += 10-i
            else: a += 10-i
            
        if r > a:
            if r-a > max_gap: 
                answer = ryan
                max_gap = r-a
                
    return answer

"""
정답 코드에선 뽑힌 인덱스 조합에대해 `ryan[10-i]`번째에 +1을 하는게 관건인것 같다. (line 9)
→ 자동적으로 ‘가장 큰 점수 차이로 이기는 경우 중에서 가장 낮은 점수를 가장 많이 맞힌 케이스’가 answer에 들어가게됨. 
  이후 같은 점수 차이가 발생해도 `r-a > max_gap` 을 만족하지 못해 갱신되지 않음.
"""
