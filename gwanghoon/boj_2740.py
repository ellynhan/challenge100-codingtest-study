import sys

def matrixMul():
    X1, X2 = map(int, sys.stdin.readline()[:-1].split())
    tmp1 = []
    for i in range(X1):
        tmp1.append(list(map(int, sys.stdin.readline()[:-1].split())))
    Y1, Y2 = map(int, sys.stdin.readline()[:-1].split())
    tmp2 = []
    for i in range(Y1):
        tmp2.append(list(map(int, sys.stdin.readline()[:-1].split())))
    result = []
    for i in tmp1:
        j = [0] * Y2

        for i, content in enumerate(i):
            mul = [content * num for num in tmp2[i]]
            j = [sum(x) for x in zip(j, mul)]
        result.append(j)
    return result

if __name__ == "__main__":
    
    result = matrixMul()
    for row in result:
        row = map(str, row)
        print(" ".join(row))

# 브론즈1 / 1시간 45분 / 브론즌데 어렵
