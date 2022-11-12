def solution(citations):
    answer = 0
    
    n = len(citations)
    
    for i in range(1, n+1):
        count = 0
        for j in citations:
            if j >= i:
                count += 1
        if i >= count:
            answer = count
            break
    
    return answer
