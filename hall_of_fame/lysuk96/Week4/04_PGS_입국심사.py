# https://programmers.co.kr/learn/courses/30/lessons/43238
# 실패
# 1트 실패 : 배수를 list에 넣어 index 구할 경우 memory 초과가 무조건 일어남 -> 1부터 최대 시간까지를 일렬로 늘어뜨려 O(logN)으로 구할것
# 2트 실패 : 29도 답이 될 수 있음. 28만 답이 되게 가장 왼쪽을 답으로 return할 것.

def solution(n, times):
    left = 1
    right = max(times)*n
    answer = 0
    
    while left <= right:
        mid = (left+right)//2
        people = 0
        for time in times :
            people+= mid//time
        if people >= n:
            right = mid - 1
            answer = mid
        elif people < n:
            left = mid + 1
        
        
    return answer