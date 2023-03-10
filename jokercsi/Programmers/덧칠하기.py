"""
n 미터의 벽
m 미터의 롤러 길이
페인트 덧칠하기 (구역 나누어 칠하기)
칠하는 규칙: 벽 벗어나지 않음, 일 부분만 칠하기 없음
"""
def solution(n, m, section):
    answer = 0
    tmp = 0
    for i in range(len(section)):
        #print(section[i])
        if section[i] <= tmp:
            #print(tmp)
            continue
            
        else:
            answer += 1
            tmp = section[i] + m -1
    
    return answer
