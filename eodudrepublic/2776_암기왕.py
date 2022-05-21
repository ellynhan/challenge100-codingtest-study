import sys

num_testcase = int(sys.stdin.readline())
for i in range(num_testcase) :
    num_note1 = int(sys.stdin.readline())
    note1 = set(map(int, sys.stdin.readline().split()))
    # 이거 왜 list를 set으로 바꾸니까 풀릴까요ㅋㅋㅋㅋㅋㅋㅋㅋㅋ
    num_note2 = int(sys.stdin.readline())
    note2 = list(map(int, sys.stdin.readline().split()))
    for i in note2 :
        if i in note1 :
            print(1)
        else :
            print(0)
