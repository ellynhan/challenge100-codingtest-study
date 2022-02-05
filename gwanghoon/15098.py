import sys
import copy
if __name__ == "__main__":
    inputLine = sys.stdin.readline()[:-1].split()
    boller = 0
    for i in inputLine:
        tmp = copy.deepcopy(inputLine)
        tmp.remove(i)
        if i in (tmp):
            boller = 1
    if boller == 1:
        print("no")
    else:
        print("yes")

# 7분
# 존나 쉬운데 문제를 잘 읽어야할듯