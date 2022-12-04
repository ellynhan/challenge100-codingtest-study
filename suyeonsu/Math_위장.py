def solution(clothes):
    d = {}
    for v, k in clothes:
        d[k] = d[k]+1 if d.get(k) else 1
    
    answer = 1
    for v in d.values():
        answer *= v+1
        
    return answer-1
    
# 해시로 분류되어 있는 문젠데 사실 수학에 더 가깝다
