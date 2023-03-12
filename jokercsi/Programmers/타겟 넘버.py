def solution(numbers, target):
    answer = 0
    leaves = [0]
    
    for i in numbers:
        tmp = []
        for parent in leaves:
            tmp.append(parent + i)
            tmp.append(parent - i)
        leaves = tmp
        
    for leaf in leaves:
        if leaf == target:
            answer += 1
    
    return answer
