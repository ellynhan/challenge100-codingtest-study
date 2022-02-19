#
#   1541
#   string
# #
# 
#

str_eval= input().split('-')
#print(str_eval)

num=[]
sum=0

for _ in str_eval:
    
    plus_cnt=0
    tmp = 0
    for j in _:
        if j =='+':
            plus_cnt+=1
    if plus_cnt>0:
        str_tmp = _.split('+')
        for j in str_tmp:
            tmp+=int(j)
        num.append(tmp)
    else:
        num.append(int(_))
#print(num)
sum = num[0]
for _ in range(1,len(num)):
    sum-=num[_]
print(sum)
