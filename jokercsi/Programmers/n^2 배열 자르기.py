def solution(n, left, right):    
    #모든 배열을 만드는게 시간이 걸린다... 
    #left 와 right의 제한이 있기때문에 그 부분만 알아내는 규칙 찾기
    
    start = divmod(left, n) 
    end = divmod(right, n)

    #1 2 3 4
    #2 2 3 4
    #3 3 3 4
    #4 4 4 4
    
    # 2차원 배열 선언하기
    array1d = []
    for i in range(start[0], end[0]+1):
        
        # 시작과 마지막이 같은 층일 때
        if i == start[0] and i == end[0]:
            for j in range(start[1], end[1]+1):
                if i > j:
                    array1d.append(i + 1)
                else:
                    array1d.append(j + 1)
        # 시작 층 일 경우
        elif i == start[0]:
            for j in range(start[1], n):
                if i > j:
                    array1d.append(i + 1)
                else:
                    array1d.append(j + 1)
            
        # 마지막 층 일 경우
        elif i == end[0]:
            for j in range(end[1]+1):
                if i > j:
                    array1d.append(i + 1)
                else:
                    array1d.append(j + 1)
        # 시작과 마지막 층 사이 일 경우
        else:
            for j in range(n):
                if i > j:
                    array1d.append(i + 1)
                else:
                    array1d.append(j + 1)
    
    return array1d
