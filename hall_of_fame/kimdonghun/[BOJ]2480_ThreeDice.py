import sys

A,B,C = map(int, sys.stdin.readline().split())
#print(A,B,C)

same_num = 0
if A == B:
    same_num = A

    if A == C:
        print(10000 + same_num * 1000)
    else:
        print(1000 + same_num * 100)
elif A == C:
    same_num = A

    print(1000 + same_num * 100)
elif B == C:
    same_num = B

    print(1000 + same_num * 100)
else:
    print(max(A,B,C) * 100)
