def solution(fees, records):
    answer = []
    car_info = {}
    car_times = {}
    LAST_TIME = 1439
    original_time, original_price, unit_time, unit_price = fees
    
    for record in records:
        day_time, car_num, park_check = record.split()
        hour, minutes = day_time.split(':')
        day_time_minutes = int(hour) * 60 + int(minutes)
        if park_check == 'IN':
            if car_num in car_info:
                car_info[car_num].append(day_time_minutes)
            else:
                car_info[car_num] = [day_time_minutes]
                car_times[car_num] = 0
        else:
            car_times[car_num] += day_time_minutes - car_info[car_num].pop()
            
    for car_num, in_time in car_info.items():
        if len(in_time) != 0:
            car_times[car_num] += LAST_TIME - in_time[0] 
            
    car_times = sorted(car_times.items())
    
    # print(car_times)
    for car_num, car_time in car_times:
        if car_time - original_time <= 0:
            answer.append(original_price)
        else:
            result = (car_time - original_time) // unit_time
            if (car_time - original_time) % unit_time > 0:
                result += 1
            answer.append(original_price + result * unit_price)
    return answer