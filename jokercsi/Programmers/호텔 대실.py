"""
최소한 객실으로 예약손님 받기
예약시간 = book_time
10분 청소 필수
필요한 최소 객실의 수
"""

"""
10분 후 계산 했을 경우 분 단위가 59넘어가면 시간 증가해야 하고 분은 오버된 수치로
바꿔줘야 합니다..!
9,17만 계속 안되서 다시 보니 그 부분이 문제였네요..
"""
def converter(in_out, string):
    h, m = string.split(':')
    if in_out == 0:
        m = int(m)
    elif in_out == 1:
        m = int(m) + 10
        
    h = int(h) * 60
    return h + m
    

def solution(book_time):
    answer = 0
    room = []
    
    # 특정 기준으로 정렬 (입장 시간 기준)
    # sort와 lambda 함수 사용하기
    book_time.sort(key = lambda x: x[0]) # ascii 코드값으로 비교 & 정렬
    
    for i in range(len(book_time)):
        
        # string
        check_in, check_out = book_time[i][0], book_time[i][1]
        
        # converter
        check_in = converter(0, check_in)
        check_out = converter(1, check_out)        
        
        #print(check_out)
        if room: # if list is not empty
            for j in range(len(room)):
                
                if room[j] <= check_in:
                    #print("check out", room[j], "check in" ,check_in)
                    # update
                    room[j] = check_out
                    break
                    
                else: 
                    if j+1 == len(room):
                        room.append(check_out)

            
        else: # if list is empty
            room.append(check_out)
    
        
    answer = len(room)
    
    return answer
