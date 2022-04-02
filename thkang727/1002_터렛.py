#
#   1002
#   수학 실버4
# #

from math import sqrt


test_case = int(input())

for i in range(test_case):
    xa,ya,ra,xb,yb,rb = map(int,input().split())
    sumr = ra+rb
    circle_r = ((xa-xb)**2 + (ya-yb)**2)**0.50
    rm = abs(ra-rb)
    if circle_r ==0:
        if ra==rb:
            print('-1')
        else:
            print('0')
    else:
        if sumr == circle_r or circle_r == rm:
            print("1")
        elif sumr > circle_r and circle_r>rm:
            print('2') 
        else:
            print('0')
