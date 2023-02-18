def solution(arr1, arr2):
    answer = []
    
    for rowindex, row in enumerate(arr1) :
        list = []
        for k in range(len(arr2[0])):
            hi = 0
            for index, j in enumerate(row):
                hi += j * arr2[index][k]
            list.append(hi)    
        answer.append(list)
            
    return answer
