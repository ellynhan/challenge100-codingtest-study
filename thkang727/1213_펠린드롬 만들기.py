#
#   펠린드롬 만들기 실버3
#   1213 문자열
#

from sys import stdin


alpha_cnt = [0 for _ in range(26)]
arr = input()

for _ in arr:
    alpha_cnt[ord(_)-65]+= 1
    
odd_cnt = 0
odd_alpha = ''
alpha =''
for i in range(26):
    if alpha_cnt[i]% 2 ==1:
        odd_cnt +=1
        odd_alpha += chr(i+65)
    alpha += chr(i+65) * (alpha_cnt[i] // 2)
    
if odd_cnt >1:
    print("I'm Sorry Hansoo")
else:
    print(alpha+odd_alpha+alpha[::-1])
        

