def solution(progresses, speeds):
    answer = []
    
    while True:
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
            
        count = 0
        if progresses[0] >= 100:
            while progresses[0] >= 100:
                progresses.pop(0)
                speeds.pop(0)
                count += 1
                if not progresses:
                    break
            answer.append(count)
        
        if not progresses:
            break
        
    
    return answer
