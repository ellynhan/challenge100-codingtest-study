def solution(n, times):
    answer = 0
    left, right = 1, max(times)*n #가장 최악의 경우는, 가장 오래 걸리는 심사위원에게 n명이 모두 가는 것임
    while left <= right:
        mid = (left + right) // 2 
        people = 0
        for time in times:
            #people은 모든 심사관들이 mid 분동안 심사한 사람의 수
            people += mid // time
            if people >= n:
                break 
                #모든 심사를 거치지 않아도 mid 분동안 n명의 심사를 할 수 있다면 나간다.
        if people >= n:
            answer = mid
            right = mid - 1
        else:
            
            left = mid + 1
            
        
    
    return answer