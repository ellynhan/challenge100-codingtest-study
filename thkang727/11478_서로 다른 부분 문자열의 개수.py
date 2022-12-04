#
#   11479   서로 다른 부분 문자열의 개수
#   문자열  실버3
# #

import sys
import math

input = sys.stdin.readline

S = input()

ans = set()

t=0
while(True):
    if t==len(S)-1:
        break
    i=0
    #tt = math.factorial(t+1)//math.factorial(i+1)
    while(i+t<len(S)-1):
        #print(S[i:i+t+1])
        if S[i:i+t+1]:
            ans.add(S[i:i+t+1])
        i+=1
    t+=1
#print(ans)
print(len(ans))
