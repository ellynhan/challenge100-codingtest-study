def solution(nums):
    answer = 0
    target = len(nums) // 2
    
    dex = set(nums)
    
    if len(dex) > target:
        answer = target
    else:
        answer = len(dex)
        
    return answer
