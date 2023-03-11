def solution(priorities, location):
    answer = 1
    list = []
    for i, v in enumerate(priorities):
        list.append((v, i)) # 처음 위치를 알기위해서 튜플로 저장하기

    while len(list):
        num = list.index(max(list,key=lambda item:item[0]))
        print(num)
        for i in range(num):
            list.append(list[i])
        del list[0:num]
        
        print(list)
        if list[0][1] == location:
            break
        else:
            del list[0]
            answer += 1
        
    return answer
