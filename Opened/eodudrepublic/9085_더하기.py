import sys

while True :
    test_case_num = int(sys.stdin.readline())
    for i in range(test_case_num) :
        result = 0
        int_num = int(sys.stdin.readline())
        data = list(map(int, sys.stdin.readline().split()))
        for j in range(int_num) :
            result += data[j]
        print(result)
    break
