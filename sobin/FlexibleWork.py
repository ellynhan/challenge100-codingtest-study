def solution(schedules, timelogs, startday):
    
    def to_minutes(t):
        return (t // 100) * 60 + (t % 100)
    
    n = len(schedules)
    answer = 0
    
    for i in range(n):
        limit = to_minutes(schedules[i]) + 10
        success = True
        
        for j in range(7):
            day = (startday + j - 1) % 7 + 1

            if day >= 6:
                continue
            
            if to_minutes(timelogs[i][j]) > limit:
                success = False
                break
        
        if success:
            answer += 1
    
    return answer
