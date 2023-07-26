import sys


while True:
    N_list = list(map(int, sys.stdin.readline().split()))

    if(N_list[0] == 0 and N_list[1] == 0 and N_list[2] == 0) :
        break

    N_list.sort(reverse=True)
    
    if(N_list[0] ** 2 == N_list[1] ** 2 + N_list[2] ** 2 ):
        print("right")
    else:
        print("wrong")
