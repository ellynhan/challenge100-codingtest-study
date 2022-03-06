import sys

class Pattern :
    __PATTERN = {0 : 1, 1 : 1, 2 : 4, 3 : 4, 4 : 2}
    def __init__(self) :
        pass
    def get(self, num) :
        num = num % 5
        return self.__PATTERN[num]

p = Pattern()

test_case_num = int(sys.stdin.readline())
for i in range(test_case_num) :
    a, b = map(int, sys.stdin.readline().split())
    a = a % 10
    if a == 0 :
        print(10)
        continue
    else :
        pass

    b_p = p.get(a)
    b = b % b_p
    if b == 0 :
        b = b_p
    else :
        pass

    print((a**b) % 10)
