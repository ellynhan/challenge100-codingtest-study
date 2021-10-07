# 01 10 15분걸림

import sys
sentence = input()

min_len = sys.maxsize
answer = ""
if sentence == sentence[::-1]:
    print(len(sentence))
    exit(0)
for i in range(len(sentence)-1, -1, -1):
    temp = sentence
    for j in range(i, -1, -1):
        temp += sentence[j]
        if temp == temp[::-1] and len(temp) < min_len:
            min_len = len(temp)
            answer = temp
            # print(f'answer: {answer}')

# print(answer)
print(len(answer))
