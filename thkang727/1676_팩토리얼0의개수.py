#
#   1676
#   수학 실버4
# #

from math import factorial
ans=0

n = int(input())
n = factorial(n)
str_n = str(n)
str_n = list(str_n)
str_n.reverse()
for _ in range(len(str_n)):
    if str_n[_] == '0':
        ans+=1
    else:
        print(ans)
        break
