import sys
import math

T = int(sys.stdin.readline())

for i in range(T) :
    N = list(map(int, sys.stdin.readline().split()))
    x1 = N[0]
    x2 = N[3]
    y1 = N[1]
    y2 = N[4]
    r1 = N[2]
    r2 = N[5]

    if(x1 == x2 and y1 == y2):
        if(r1 == r2):
            print(-1)
        else:
            print(0)

        continue
    
    dot_distant = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    dist_sum = r1+r2
    dist_sub = abs(r1-r2)

    if(dist_sub < dot_distant and dist_sum > dot_distant):
        print(2)
    else:
        if(dist_sum == dot_distant or dist_sub == dot_distant):
            print(1)
        else:
            print(0)
    