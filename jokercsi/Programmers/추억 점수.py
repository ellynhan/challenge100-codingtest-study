'''
추억 점수 (인물의 그리움 점수)
'''
def solution(name, yearning, photo):
    answer = []
    dict = {}
    for i, v in enumerate(name):
        dict[v] = yearning[i]
    #print(dict)
    
    for i in photo:
        sum = 0
        for j in i:
            try:
                sum += dict[j]
            except:
                print(j)
        answer.append(sum)
    return answer
