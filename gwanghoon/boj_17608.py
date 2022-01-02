import sys

def makeLineStack(lineStack, stackLen):
    for i in range(stackLen):
        line = int(sys.stdin.readline()[:-1])
        lineStack.append(line)

def numVisibleInd(inputStack):
    max = 0
    result = 0
    for i in range(len(inputStack) - 1, -1, -1):
        if inputStack[i] > max:
            max = inputStack[i]
            result += 1
    return result

if __name__ == "__main__":
    lineStack = []
    stackLen = int(sys.stdin.readline()[:-1])
    makeLineStack(lineStack, stackLen)
    print(numVisibleInd(lineStack))


# solved domain : stack
# time consumed : 09:20
# incorrect count : 1
# time over : 0
# note : range함수는 (start, end, scale)로 정의되며 start 부터 end - scale 까지만 계산이 된다.