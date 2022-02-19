#
#   1541
#   string
# #
# 
#



num_str = list(input())
num_str.sort(reverse=True)
sum = 0
zero_cnt =0 
ans=""
for _ in num_str:
    sum +=int(_)
    if _ == '0':
        zero_cnt+=1

if zero_cnt<=0:
    print('-1')
else:
    if sum %3 !=0 :
        print('-1')
    elif sum<3:
        print('-1')
    else:
        print("".join(num_str))
