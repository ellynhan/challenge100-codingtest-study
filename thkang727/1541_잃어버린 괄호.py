#
#   1541
#   string
# #
# 
#

str_eval= input().split('-')
num = []
for _ in str_eval:
    cnt = 0
    s = _.split('+')
    for j in s:
        cnt += int(j)
    num.append(cnt)
n = num[0]
for i in range(1, len(num)):
    n -= num[i]
print(n)

            

