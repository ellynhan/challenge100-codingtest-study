import sys

N = int(sys.stdin.readline())

while N > 1 :    
    for div_num in range(2, N+1) :
        if N % div_num == 0 :
            N //= div_num
            print(div_num)
            break