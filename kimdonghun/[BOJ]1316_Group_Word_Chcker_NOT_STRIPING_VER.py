import sys

N = sys.stdin.readline()
group_word_cnt = 0
group_word_flag = True
group_checker = [0] * 26

for i in range(int(N)) :
    word = sys.stdin.readline()
    group_word_flag = True
    group_checker = [0] * 26
    #print(len(word))

    for j in range(len(word) - 1) :
        if word[j] != word[j+1] :
            group_checker[ord(word[j]) - 97] += 1
    
    #print(group_checker)

    for k in range(len(group_checker)) :
        if(group_checker[k] > 1) :
            group_word_flag = False
    
    if(group_word_flag) :
        group_word_cnt += 1
        #print(word + "==")

print(group_word_cnt)