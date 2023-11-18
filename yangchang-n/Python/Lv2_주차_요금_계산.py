def cal_time(carin, carout) :
    carin = list(map(int, carin.split(':')))
    carout = list(map(int, carout.split(':')))
    if carout[1] < carin[1] :
        carout[1] += 60
        carout[0] -= 1
    return (carout[0] - carin[0]) * 60 + (carout[1] - carin[1])    

def cal_fee(totaltime, fees) :
    if totaltime <= fees[0] :
        return fees[1]
    totaltime -= fees[0]
    fee = fees[1] + (int((totaltime + fees[2] - 1)/fees[2]) * fees[3])
    return fee
    
def solution(fees, records) :
    answer = []
    rec_list = []
    for i in records :
        rec_list.append(i.split(' '))
    rec_list.sort(key = lambda x : x[1])
    print(rec_list)
    time = 0
    if len(rec_list) == 1 :
        return [cal_fee(cal_time(rec_list[0][0], '23:59'), fees)]
    for j in range(len(rec_list) - 1) :
        if rec_list[j][1] != rec_list[j + 1][1] :
            if rec_list[j][2] == 'IN' :
                time += cal_time(rec_list[j][0], '23:59')
            answer.append(cal_fee(time, fees))
            time = 0
        elif rec_list[j][2] == 'IN' :
            time += cal_time(rec_list[j][0], rec_list[j + 1][0])
    if rec_list[-1][2] == 'IN' :
        time += cal_time(rec_list[-1][0], '23:59')
    answer.append(cal_fee(time, fees))            
    return answer
