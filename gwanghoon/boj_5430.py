import sys

def makeList(inputList):
    intArray = inputList[1:-2].split(",")
    return intArray

def operation(instruction, testsize):
    inputList = sys.stdin.readline()
    intArray = makeList(inputList)
    num_reverse = 0
    for i in instruction:
        if (i == "R"):
            num_reverse += 1
        if (i == "D"):
            if testsize == 0:
                return "error"
            if (num_reverse % 2) == 0:
                del intArray[0]
            if (num_reverse % 2) == 1:
                del intArray[-1]
    if (num_reverse % 2) == 1:
        intArray.reverse()

    arrToText = ",".join([str(i) for i in intArray])
    return f"[{arrToText}]"

if __name__ == "__main__":
    testcase = int(sys.stdin.readline())
    result = []
    for i in range(0,testcase):
        instruction = sys.stdin.readline()
        testsize = int(sys.stdin.readline())
        try:
            result.append(operation(instruction, testsize))
        except:
            result.append("error")
    print("\n".join(result))
