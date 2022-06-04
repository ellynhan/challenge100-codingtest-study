#
#   문자열 실버4
#   9012 괄호
#

import sys
from sys import stdin


t = int(stdin.readline())

for i in range(t):
    are = list(stdin.readline())
    #print(are)
    onum, clnum = 0, 0
    passif = False
    if are[0]== ')' or are[len(are)-1]=='(':
        print('NO')
    else:    
        for j in range(len(are)):
            if are[j] == '(':
                onum+=1
            elif are[j] == ')':
                clnum+=1
            if onum < clnum:
                print('NO')
                passif = True
                break
        if passif == False:
            if onum == clnum:
                print('YES')
            else:
                print('NO')


