from copy import deepcopy

def solution(n, results) :
    result_table = [[0] * (n + 1) for i in range(n + 1)]
    for i in range(len(results)) :
        result_table[results[i][0]][results[i][1]] = 1
        result_table[results[i][1]][results[i][0]] = -1    
    # while True :
    #     check_table = deepcopy(result_table)
    for j in range(1, n + 1) :
        for k in range(1, n + 1) :
            if result_table[k][j] != 0 :
                for l in range(1, n + 1) :
                    if result_table[j][l] == result_table[k][j] :
                        result_table[k][l] = result_table[k][j]
        # if check_table == result_table :
        #     break
    answer = 0                    
    for m in range(1, n + 1) :
        if result_table[m].count(0) == 2 :
            answer += 1
    return answer

# while문 없어도 되는거 확인해보기
