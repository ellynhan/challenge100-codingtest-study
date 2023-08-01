import math

def solution(li, i, add, minus, x, y):
    answer = 200_000_000_000_000_000
    if add == 0 and minus == 0: return (x ** 2 + y ** 2)

    if add != 0:
        s = solution(li, i+1, add-1, minus, x+li[i+1][0], y+li[i+1][1])
        if(s < answer): answer = s
    
    if minus != 0:
        s = solution(li, i+1, add, minus-1, x-li[i+1][0],y-li[i+1][1])
        if(s < answer): answer = s

    return answer


def main():
    T = int(input())
    answer = []
    while T != 0:
        n = int(input())
        li = []
        tmp1 = [0, 0]
        li.append(tmp1)
        for i in range(n):
            tmp = [int(x) for x in input().split()]
            li.append(tmp)
        
        subAnswer = solution(li, 0, n/2, n/2, 0, 0)

        answer.append(math.sqrt(subAnswer))
        T -= 1

    for i in answer:
        print(i)

if __name__ == "__main__":
    main()
