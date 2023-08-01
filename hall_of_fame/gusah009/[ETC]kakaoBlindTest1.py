def solution(id_list, report, k):
    answer = [0 for col in range(len(id_list))]
    array = [[0 for col in range(1000)] for row in range(1000)]
    id_dict = {}
    i = 0
    for index, id in enumerate(id_list):
        id_dict[id] = index

    for declaration in report:
        a, b = declaration.split()
        array[id_dict[b]][id_dict[a]] = 1

    report_num = []
    for index, _ in enumerate(id_list):
        result = 0
        for index2, _  in enumerate(id_list):
            result += array[index][index2]
        if result >= k:
            for index2, _  in enumerate(id_list):
                if array[index][index2] == 1:
                    answer[index2] += 1
            
    # print(report_num)
    return answer