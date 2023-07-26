import sys

N = int(sys.stdin.readline())
word_list = []
word_dict = {}

for i in range(N):
    word_list.append(sys.stdin.readline()[:-1])
    
for word in word_list:

    digit_sqrt = len(word) - 1

    for c in word:
        if c in word_dict:
            word_dict[c] += pow(10, digit_sqrt)
        else:
            word_dict[c] = pow(10, digit_sqrt)

        digit_sqrt -= 1

#print(word_dict)

num_list = sorted(word_dict.values(), reverse=True)

#new_num_list = sorted(word_dict.items())
#print(new_num_list)

cur_num = 9
result = 0

#print(num_list)

for num in num_list:
    result +=  int(num) * cur_num

    cur_num -= 1

print(result)
