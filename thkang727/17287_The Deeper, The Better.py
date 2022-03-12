#
#   1149
#   string
# #
# 열린 부분만 읽어서 점수?
#

str_num = input()
small_cnt, middle_cnt, big_cnt = 0,0,0
ans = 0
highscore = 0
for _ in str_num:
    if _ == '(':
        small_cnt+=1
    elif _ == '{':
        middle_cnt+=1
    elif _ == '[':
        big_cnt+=1
    elif _ == ')':
        small_cnt-=1
    elif _ == '}':
        middle_cnt-=1
    elif _ == ']':
        big_cnt-=1
    else:
        ans = small_cnt + middle_cnt*2 + big_cnt*3
        
        if ans > highscore:
            highscore = ans

print(highscore)
