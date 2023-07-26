import sys

my_list = list(sys.stdin.readline()[:-1])
cnt_list = [0] * 26

for i in range(97, 123) :
    cnt_list[i-97] += my_list.count(chr(i))

for i in range(65, 91) :
    cnt_list[i-65] += my_list.count(chr(i))

max_cnt = -1
most_chr = ""

for i in range(26) :
    if max_cnt < cnt_list[i] :
        max_cnt = cnt_list[i]
        most_chr = chr(65 + i)
    elif max_cnt == cnt_list[i] :
        most_chr = "?"


print(most_chr)