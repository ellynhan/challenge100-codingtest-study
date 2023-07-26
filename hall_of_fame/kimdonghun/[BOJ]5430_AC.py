import sys
from collections import deque

T = int(sys.stdin.readline())

for i in range(T):
    p = list(sys.stdin.readline()[:-1])
    N = int(sys.stdin.readline())
    arr_l = deque(list(sys.stdin.readline()[1:-2].split(",")))

    #print(p)
    #print("==", p, N, arr_l)

    if arr_l[0] == "":
        arr_l.popleft()

    #print("**", p.count("D"))
    if p.count("D") > len(arr_l):
        print("error")
        continue

    reverse_flag = False
    reverse_cnt = 0
    try: 
        for c in p:
            if c == "R":
                if reverse_flag == True:
                    reverse_flag = False
                else:
                    reverse_flag = True
                reverse_cnt += 1
            elif c == "D":
                if reverse_flag == True:
                    arr_l.pop()
                else:
                    arr_l.popleft()
    except IndexError:
        print("error")
        continue

    if reverse_cnt % 2 == 1:
        arr_l.reverse() 
    
    print("[", end="")
    for i in range(len(arr_l)):
        if i < len(arr_l) - 1:
            print(arr_l[i], end="," )
        else:
            print(arr_l[i], end="" )
    print("]")
