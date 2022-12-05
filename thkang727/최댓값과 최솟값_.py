def solution(s):
    answer = ''
    tmp = []
    min_int = 999999
    max_int = -999999
    
    tmp = s.split(" ")

    for i in tmp:
        print(int(i))
        if max_int<int(i):
            max_int = int(i)
        if min_int>int(i):
            min_int=int(i)
            
    answer = str(min_int) +" " + str(max_int)
    return answer
