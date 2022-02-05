# https://programmers.co.kr/learn/courses/30/lessons/17680
# 예외 처리 : 0, ["LA","LA"]
from collections import deque
def solution(cacheSize, cities):
    answer = 0
    cnt = 0
    q = deque(cities)
    cache = deque([])
    
    while q:
        tmp = q.popleft().lower()
        if tmp not in cache:
            if cnt < cacheSize:
                cnt+=1
                cache.append(tmp)
            else:
                if cache:
                    cache.popleft()
                    cache.append(tmp)
            answer+=5
        else:
            answer+=1
            cache.remove(tmp)
            cache.append(tmp)
            
        
    return answer