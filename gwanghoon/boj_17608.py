"17608 브론즈2"
import sys

def makeStickList(size):
    temp = []
    for i in range(size):
        x = int(sys.stdin.readline())
        temp.append(x)
    return temp

def sol(stickList):
    stickList.reverse()
    max = stickList[0]
    result = 1
    for i in stickList:
        if i > max:
            max = i
            result +=1
    return result


if __name__ == "__main__":
    size = int(sys.stdin.readline())
    SL = makeStickList(size)
    result = sol(SL)
    print(result)

"32분 45초: input()은 시간초과 뜨니 sys.stdin.readline() 사용하기"
