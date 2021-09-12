import sys

def lineList(lineSize):
    temp = []
    for i in range(lineSize):
        x = sys.stdin.readline()
        x = x[:-1].split()
        x.reverse()
        temp.append(" ".join(x))
    return temp
        
def printResult(lineList):
    iter = 0
    for i in lineList:
        iter += 1
        print(f"Case #{iter}:",i)

if __name__ == "__main__":
    line = int(sys.stdin.readline())
    printResult(lineList(line))
