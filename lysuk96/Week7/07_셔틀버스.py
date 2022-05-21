#https://programmers.co.kr/learn/courses/30/lessons/17678
#마지막 탈때의 경우의 수를 겹치지 않게 잘 나누자 (여기서 30분 소요)

from collections import deque
def solution(n, t, m, timetable):
    timetable.sort()
    q = deque(timetable)
    now = "09:00"
    answer = ''
    
    seat = 0
    for i in range(n-1):
        for _ in range(m):
            if q and q[0] <= now:
                q.popleft()
            else: break
                
        hour = int(now.split(":")[0])
        minute = int(now.split(":")[1])
        now = str(hour + (minute+t)//60).zfill(2) + ":" + str((minute+t)%60).zfill(2)
        # print(now)
    
    # 마지막 탈때
    if len(q) < m:
        answer = now
    else:
        if q[m-1] > now:
            answer = now
        else:
            cnt = 1
            while cnt <= m and q[m-cnt] == q[m-1]:
                cnt+=1
            answer = q[m-cnt+1]
            hour = int(answer.split(":")[0])
            minute = int(answer.split(":")[1])
            answer = str(hour + (minute-1)//60).zfill(2) + ":" + str((minute-1)%60).zfill(2)
            
        
    # print(q)
    return answer