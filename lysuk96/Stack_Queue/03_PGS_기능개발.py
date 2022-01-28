# 기능개발
from collections import deque
from math import ceil

def solution(progresses, speeds):
    tasks_num = len(progresses)
    q = deque([(ceil((100 - progresses[i])/speeds[i])) for i in range(tasks_num) ]) #ceil 안쓰고 -(p - 100)//s 해도 됨 -> 올림한 양수

    answer = []

    while q:
        if q[0] ==0:
            tmp = 1
            q.popleft()
            while q and q[0] ==0 :
                tmp +=1
                q.popleft()
            answer.append(tmp)
        # print(q)
        for i in range(len(q)): #더 짧게 못바꾸나? map & lambda 사용? -> 공간 복잡도 높아지나?
            if q[i] >0: 
                q[i] -= 1
    
    # print(answer)
    return answer

solution([95, 90, 99, 99, 80, 99],[1, 1, 1, 1, 1, 1])

# 다른 사람 예술 풀이  -> O(N)으로 효율성 극대화 (필요 날짜, 해당 날짜 배포 가능 기능수)
# def solution(progresses, speeds):
#     Q=[]
#     for p, s in zip(progresses, speeds):
#         if len(Q)==0 or Q[-1][0]<-((p-100)//s):
#             Q.append([-((p-100)//s),1])
#         else:
#             Q[-1][1]+=1
#     return [q[1] for q in Q]