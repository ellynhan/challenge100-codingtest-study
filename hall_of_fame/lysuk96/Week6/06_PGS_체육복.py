#https://programmers.co.kr/learn/courses/30/lessons/42862
def solution(n, lost, reserve):
    cloth = [1]*n
    for i in lost:
        cloth[i-1]-=1
    for i in reserve:
        cloth[i-1]+=1
    
    if cloth[0] == 2 and cloth[1] == 0:
        cloth[0], cloth[1] = 1, 1
        
    if cloth[n-1] == 2 and cloth[n-2] == 0:
        cloth[n-1], cloth[n-2] = 1, 1
        
    for i in range(1, n-1):
        if cloth[i] == 2:
            if cloth[i-1] == 0:
                cloth[i], cloth[i-1] = 1, 1
            elif cloth[i+1] == 0:
                cloth[i], cloth[i+1] = 1, 1
    return n-cloth.count(0)