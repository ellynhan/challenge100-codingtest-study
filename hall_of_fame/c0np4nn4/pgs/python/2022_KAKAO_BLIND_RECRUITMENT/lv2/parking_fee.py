import collections
import math

def solution(fees, records):
    answer = []

    in_time = collections.defaultdict(int)
    park_time = collections.defaultdict(int)

    for r in records:
        time, number, status = r.split(" ")

        number = int(number, 10)

        if status == "IN":
            hour = int(time.split(":")[0], 10)
            min = int(time.split(":")[1], 10)
            in_time[number] = hour * 60 + min

        if status == "OUT":
            hour = int(time.split(":")[0], 10)
            min = int(time.split(":")[1], 10)
            out_time = hour * 60 + min
            parking_time = out_time - in_time[number]
            park_time[number] += parking_time
            in_time[number] = -1

            
    for number in in_time:
        if in_time[number] != -1:
            last_time = 23 * 60 + 59
            park_time[number] += last_time - in_time[number]

    print(park_time)
    park_time = sorted(park_time.items())
    print(park_time)

    for (_, time) in park_time:
        if time <= fees[0]:
            answer.append(fees[1])
        else:
            answer.append(fees[1] + math.ceil((time - fees[0]) / fees[2]) * fees[3])

    print(answer)

    return answer

# fees = [180, 5000, 10, 600]
# records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
# result = [14600, 34400, 5000]

fees = [1, 461, 1, 10]
records = ["00:00 1234 IN"]
result = [14841]

if result == solution(fees, records):
    print("good")
else:
    print("wrong")
