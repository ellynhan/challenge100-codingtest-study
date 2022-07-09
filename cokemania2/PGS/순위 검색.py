def is_last_element(info):
    return len(info) == 2

def save(dic, info):
    if len(info) == 0:
        return

    if info[0] in dic:
        if is_last_element(info):
            dic[info[0]].append(int(info[1]))
            dic[info[0]] = sorted(dic[info[0]])
        else:
            save(dic[info[0]], info[1:])
    else:
        if is_last_element(info):
            dic[info[0]] = [int(info[1])]
        else:
            dic[info[0]] = {}
            save(dic[info[0]], info[1:])

def select(dic, info):
    if len(info) == 1:
        info = info[0].split()
        if info[0] == '-':
            answer = 0
            for k in dic.keys():
                answer += find_answer(dic[k], int(info[1]))
            return answer

        if info[0] in dic:
            return find_answer(dic[info[0]], int(info[1]))
        return 0

    if info[0] == '-':
        answer = 0
        for k in dic.keys():
            answer += select(dic[k], info[1:])
        return answer
    
    if info[0] in dic:
        return select(dic[info[0]], info[1:])
    return 0

def binary_serach(arr, target, start, end):
    mid = 0
    while start <= end:
        mid = (start+end)//2
        if arr[mid] >= target:
            end = mid-1
        else:
            start = mid + 1
    return len(arr)- mid - (1 if arr[mid] < target else 0)

def find_answer(arr, target):
    return binary_serach(arr, target, 0, len(arr)-1)

def solution(info, query):
    answer = []
    dic = {}
    
    for i in info:
        save(dic, i.split(' '))
    
    for q in query:
        answer.append(select(dic, q.split(' and ')))    
    
    return answer

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
print(solution(info, query))