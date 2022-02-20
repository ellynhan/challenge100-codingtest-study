#https://programmers.co.kr/learn/courses/30/lessons/17682
#너무 난잡하게 풀었나?
def solution(dartResult):
    res = []
    sdt = ['S','D','T']
    idx = 0
    while idx < 3:
        num = int(dartResult[0])
        if dartResult[1]=='0':
            num = int(dartResult[:2])
            dartResult = dartResult[1:]
            
        if dartResult[1] in sdt:
            res.append(num**(sdt.index(dartResult[1])+1))

        cnt = 2
        if len(dartResult) > 2:
            if dartResult[2] == '*':
                if idx != 0:
                    res[idx-1] *= 2
                res[idx] *= 2
                cnt+=1
            elif dartResult[2] == '#':
                res[idx] *= -1
                cnt+=1
        if idx < 2:
            dartResult = dartResult[cnt:]
            # print(idx, dartResult)
        idx+=1
        

    # print(res)
    return sum(res)