import sys
import math

T = int(sys.stdin.readline())

for i in range(T) :
    H,W,N = map(int, sys.stdin.readline().split())
    Y = (N % H)
    X = (N // H) + 1
    
    if Y == 0 :
        Y = H
        X = (N // H)

    print("{}{:02d}".format(Y,X))