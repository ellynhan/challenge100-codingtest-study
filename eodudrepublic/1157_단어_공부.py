import sys

input_str = sys.stdin.readline().strip()
input_str = input_str.upper()
input_str = list(input_str)
input_str.sort()

temp_index = 0
str_dic = {}
while temp_index < len(input_str) :
    temp = input_str[temp_index]
    temp_count = input_str.count(temp)
    str_dic[temp] = temp_count
    temp_index += temp_count

output_str = ''
max_count = 0
str_list = str_dic.keys()
for i in str_list :
    temp_count = str_dic[i]
    if max_count < temp_count :
        max_count = temp_count
        output_str = i
    elif max_count == temp_count :
        output_str = '?'
print(output_str)
