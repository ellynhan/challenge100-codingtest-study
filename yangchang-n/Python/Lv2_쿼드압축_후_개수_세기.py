answer = [0, 0]

def solution(arr) :
    if all(1 not in p for p in arr) :
        answer[0] += 1
    elif all(0 not in q for q in arr) :
        answer[1] += 1
    else :
        n = int(len(arr) / 2)
        a, b, c, d = [], [], [], []
        for i in range(n) :
            a.append(arr[i][:n])
            b.append(arr[i][n:n*2])
            c.append(arr[n+i][:n])
            d.append(arr[n+i][n:n*2])
        solution(a)
        solution(b)
        solution(c)
        solution(d)
            
    return answer
