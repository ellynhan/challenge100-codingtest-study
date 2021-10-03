import sys
def makeNangZangList():
    NangZangList = []
    for i in range(9):
        x = sys.stdin.readline()[:-1]
        NangZangList.append(int(x))
    return NangZangList

def sumHeight(ls, i, j):
    result = 0
    for x in range(len(ls)):
        result += ls[x]
    return result - ls[i] - ls[j]

def trueNangZangList(ls):
    for i in range(len(ls)-1):
        for j in range(i+1, len(ls)):
            criteria = sumHeight(ls, i, j)
            if (criteria == 100):
                ls.remove(ls[i])
                ls.remove(ls[j-1])
                ls.sort()
                return ls


if __name__ == "__main__":
    x = makeNangZangList()
    y = trueNangZangList(x)
    for i in y:
        print(i)
