"""
숫자 문자열
p의 길이
"""
def solution(t, p):
    answer = 0

    n = len(p)
    
    for i in range(0, len(t)):

        if i+n > len(t):
            #print(t[i:i+n])
            continue
        else:
            #print(t[i:i+n], p)
            if int(t[i:i+n]) <= int(p):
                answer += 1
            
    return answer
