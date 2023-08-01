import sys
import math

A,B,V = map(int, sys.stdin.readline().split())

ans = 1
V -= A

if(V <= 0) :
    print(ans)
else :
    V = math.ceil((V / (A -B)))
    ans += V
    print(ans)



'''
while V >= 0 :
    i += 1
    V -= A

    if V <= 0 :
        break

    V += B
'''

