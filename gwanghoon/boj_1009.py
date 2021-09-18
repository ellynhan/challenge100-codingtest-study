import sys

def numData():
    inputNumber = sys.stdin.readline()

    a,b = inputNumber.split()
    if b == "0":
        return "1"
    if a == "0":
        return "0"
    a = a[-1]
    if a == "0":
        return "10"
    if a in ["1","5","6"]:
        return a
    if a == "2":
        if (int(b)%4) == 0:
            return "6"
        if (int(b)%4) == 1:
            return "2"
        if (int(b)%4) == 2:
            return "4"
        if (int(b)%4) == 3:
            return "8"
    if a == "3":
        if (int(b)%4) == 0:
            return "1"
        if (int(b)%4) == 1:
            return "3"
        if (int(b)%4) == 2:
            return "9"
        if (int(b)%4) == 3:
            return "7"
    if a == "7":
        if (int(b)%4) == 0:
            return "1"
        if (int(b)%4) == 1:
            return "7"
        if (int(b)%4) == 2:
            return "9"
        if (int(b)%4) == 3:
            return "3"
    if a == "8":
        if (int(b)%4) == 0:
            return "6"
        if (int(b)%4) == 1:
            return "8"
        if (int(b)%4) == 2:
            return "4"
        if (int(b)%4) == 3:
            return "2"
    if a == "4":
        if (int(b)%2) == 0:
            return "6"
        if (int(b)%2) == 1:
            return "4"
    if a == "9":
        if (int(b)%2) == 0:
            return "1"
        if (int(b)%2) == 1:
            return "9"

if __name__ == "__main__":
    TestCase = sys.stdin.readline()
    result = list(map(lambda x : numData(), range(0,int(TestCase))))

    for i in result:
        print(i)
"""브3 42분20초"""
