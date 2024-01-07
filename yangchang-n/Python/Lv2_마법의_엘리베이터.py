def solution(storey) :
    answer = 0
    while True :
        if storey == 0 :
            break
        storey, num = storey // 10, storey % 10
        if num > 5 :
            answer += 10 - num
            storey += 1
        elif num < 5 :
            answer += num      
        else :
            if storey % 10 >= 5 :
                answer += 10 - num
                storey += 1
            else :
                answer += num

    return answer
