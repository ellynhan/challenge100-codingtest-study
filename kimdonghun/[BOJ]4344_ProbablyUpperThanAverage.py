import sys

C = int(sys.stdin.readline())

for i in range(C) :
    tmp_list = list(map(int, sys.stdin.readline().split()))

    N = tmp_list[0]
    std_score = tmp_list[1:]

    sum = 0
    avg = 0

    for j in range(N) :
        sum += std_score[j]

    avg = sum / N
    upper_std = 0

    for j in range(N) :
        if avg < std_score[j] :
            upper_std += 1

    #print( "{:.3f}".format(round(upper_std / N * 100 , 3)) + "%")
    print( f"{upper_std / N * 100:.3f}%")
