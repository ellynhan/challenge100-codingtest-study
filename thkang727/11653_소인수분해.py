#
#   11653
#   수학 실버5
# #

import sys
input = sys.stdin.readline

n = int(input())
so=2
while n!=1:
    if n%so ==0:
        n/=so
        print(so)
    else:
        so+=1
