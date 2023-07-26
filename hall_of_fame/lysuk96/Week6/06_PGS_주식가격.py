#https://programmers.co.kr/learn/courses/30/lessons/42584

# queue 쓰는 풀이
import collections
def solution(prices):
    q = collections.deque(prices)
    answer =[]
    while len(q)>=2:
        tmp = q.popleft()
        time = 0
        for price in prices:
            time += 1
            if tmp > price:
                break
        answer.append(time)

    answer.append(0)
    return answer

#다른 내풀이 질문 : 위와 같은 로직인데 왜 더 느릴까?
def solution(prices):
    n = len(prices)
    answer = [0] * n
    
    for i in range(n-1):
        for j in range(i+1, n):
            # print(i, j)
            if prices[i] <= prices[j]:
                answer[i]+=1
            else:
                answer[i]+=1
                break
        
    return answer