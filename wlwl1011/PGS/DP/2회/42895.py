def solution(N, number):
    answer = 0
    if N == number:
        return 1
    flag = False
    s = [ set() for _ in range(9) ]
    
    for i in range(1,9):
        s[i].add(str(N)*(i))

    for i in range(2,9):
        for j in range(1,i):
            k = i-j
            for index_j in s[j]:
                for index_k in s[k]:
                    a = int(index_j)
                    b = int(index_k)
                    #더하기
                    s[i].add(str(a + b))
                    
                    #빼기
                    s[i].add(str(a - b))
                    #곱하기
                    s[i].add(str(a * b))
                    
                    #나누기
                    if b !=0  :
                        s[i].add(str(a//b))
            
        if str(number) in s[i]:
            flag = True
            answer = i
            break
        if flag:
            break
    if not flag:
        answer = -1
    return answer