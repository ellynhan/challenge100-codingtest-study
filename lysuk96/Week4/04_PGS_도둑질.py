# https://programmers.co.kr/learn/courses/30/lessons/42897
# 1트 실패 : 반례(10, 2, 2, 100, 2) -> 110이 답인데 102
# 키포인트 : 경우의 수 나누기 (첫번째 집 텀, 안텀)

def solution(money):
    length = len(money)
    
    dp1 = [0] * length #첫번째 집 안텀
    dp2 = [0] * length #첫번째 집 텀
    dp1[1] = money[1]
    dp2[0] = money[0]
    dp2[1] = money[0]
    
    for i in range(2, length-1):
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])
    dp1[-1] = max(dp1[-2], dp1[-3] + money[-1])
    dp2[-1] = dp2[-2]
        
    # print(dp1, dp2)
    return max(dp1[-1], dp2[-1])