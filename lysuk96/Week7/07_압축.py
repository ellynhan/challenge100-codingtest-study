#https://programmers.co.kr/learn/courses/30/lessons/17684
from collections import defaultdict
import string
def solution(msg):
    answer = []

    alphabet = [x for x in string.ascii_letters[26:]]
    dic = defaultdict(int)
    for i in range(26):
        dic[alphabet[i]] = i+1

    serial = 27
    while msg != '':
        idx = 1
        while dic[msg[:idx]] != 0 and idx <= len(msg):
            idx+=1
        answer.append(dic[msg[:idx-1]])
        if dic[msg[:idx]] == 0:
            dic[msg[:idx]] = serial
        # print(msg[:idx])
        # print(dic)
        serial+=1
        msg = msg[idx-1:]
        # print(msg)

    return answer