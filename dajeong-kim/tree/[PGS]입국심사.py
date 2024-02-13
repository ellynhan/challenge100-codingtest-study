def solution(n, times):
    answer = 0
    left, right = 1, max(times)*n
    
    while left<=right:
        people = 0
        mid = (left+right) //2
        
        for time in times:
            people += mid // time  
            if people >= n:
                break
        
        if people>=n:
            answer = mid
            right = mid - 1 
            
        else:
            left = mid + 1
            
    return answer