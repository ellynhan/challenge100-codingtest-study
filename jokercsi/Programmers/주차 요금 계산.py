"""
주차 요금 계산하기
기본 시간 - 기본 요금 [180, 5000]
단위 시간 - 단위 요금 [10, 600]

출차된 내역이 없다면, 23:59에 출차된 것으로 간주한다
기본 시간이하라면, 기본 요금
기본 시간을 초과하면, 기본 요금에 더해서, 초과한 시간에 대해서 단위 시간 마다 단위 요금
"""


# 올림 가져오기
import math

def solution(fees, records):
    answer = []
    
    base_min = fees[0]
    base_rate = fees[1]
    plus_min = fees[2]
    plus_rate = fees[3]
    
    cars = []
    time = []
    histories = []
    
    for i in records:
        
        word = i.split(' ')
        
        #리스트에 차가 없고 입차이면
        if word[1] not in cars and word[2] == "IN":
                        
            cars.append(word[1])
            
            # 시간을 분으로 바꾸기
            H_M = word[0].split(':')
            hour = int(H_M[0])
            minute = int(H_M[1])
            total_minute = (hour * 60) + minute
            
            time.append(total_minute)
            
        # 리스트에 차가 있고 출차이면
        # 이미 들어와 있었는지 확인
        # 차번호와 시간을 함께 저장 출력
        elif word[1] in cars and word[2] == "OUT": 
            num = cars.index(word[1])
            
            # 시간을 분으로 바꾸기
            H_M = word[0].split(':')
            hour = int(H_M[0])
            minute = int(H_M[1])
            total_minute = (hour * 60) + minute
            
            parking_time = total_minute - time[num]
            #print(parking_time, word[1])
            
            # 지우기
            del cars[num]
            del time[num]
            
            car = [word[1], parking_time] 

            # 공백일 경우
            if not histories:
                histories.append(car)
            # 공백이 아닐 경우
            else:
                # 이미 입차 이력있다면
                count = 0
                for i in histories:
                    # 값 더하기
                    if word[1] in i:
                        i[1] += parking_time
                        break
                    count+=1

                # 찾는데 없었다면
                if count == len(histories):
                    print()
                    histories.append(car)
            
    # 리스트에 차가 있고 출차가 없으면
    if cars:     
        for index in range(len(cars)):
            
            #23:59 까지
            last_min = 1439 
            parking_time = last_min - time[index] 

            car = [cars[index], parking_time] 
            count = 0
            for i in histories:
                
                if cars[index] in i:

                    i[1] += parking_time
                    break
                count+=1
            # 찾는데 없었다면
            if count == len(histories):
                histories.append(car)
            
    # 차량 번호가 작은 순으로 만들기
    #print(histories)
    histories = sorted(histories, key=lambda x: x[0])

    
    # 마지막 주차 계산
    for j in histories:
        # 기본 요금
        if j[1] < base_min:
            result = base_rate
        # 기본 시간 초과할 경우
        else:
            # 올림해야됨
            result = base_rate + math.ceil((j[1] - base_min) / plus_min) * plus_rate
        answer.append(result)

    return answer
