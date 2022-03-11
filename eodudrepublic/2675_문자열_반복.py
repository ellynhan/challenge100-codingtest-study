import sys

test_case_num = int(sys.stdin.readline())
for t in range(test_case_num) :
    r, S = sys.stdin.readline().strip().split()
    R = int(r)
    for s in S :
        for i in range(R) :
            print(s, end='')
    print()
