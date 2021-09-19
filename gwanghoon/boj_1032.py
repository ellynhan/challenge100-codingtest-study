import sys

def inputFile():
    filename = sys.stdin.readline()
    return filename[:-1]

def isSame(someList):
    if len(set(someList)) == 1:
        return True
    else:
        return False 

def searchResult(numFiles):
    files = []
    result = ""
    for i in range(numFiles):
        files.append(inputFile())
    length = len(files[0])

    for i in range(length):
        tempList = []
        for file in files:
            tempList.append(file[i])
        if isSame(tempList):
            result += file[i]
        else:
            result += "?"
    return result

if __name__ == "__main__":
    TestCase = int(sys.stdin.readline())
    print(searchResult(TestCase))

    """브1 12분 30초"""
