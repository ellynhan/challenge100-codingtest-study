def solution(clothes):
    answer = 0
    d = {} #dictionary
    
    for i in clothes:
        if i[1] in d: # 같은 key가 이미 있다면
            d[i[1]].append(i[0]) 
        else:
            d.update({i[1]: [i[0]]}) #value는 리스트로 만드는게 중요
    
    num = 0
    
    len(d) # 옷 종류의 갯수
    
    dic_values = d.values()
    dic_values = list(dic_values) # list로 바꿔주어야한다.
    
    answer = 1
    for i in dic_values:
        print(len(i)+1)
        answer *= len(i)+1
        
    answer = answer - 1
    return answer
