import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
from itertools import permutations

arr = [i for i in range(10)]

N = int(input())
p = list(input().split())
answer = []
for a in permutations(arr,N+1):
    flag = True
    a = list(a)
    # print('.....')
    # print(a)
    for i in range(N):
        # print(p[i])
        # print(a[i],a[i+1])
        if p[i] == '<':
            if not (int(a[i]) < int(a[i+1])):
                flag = False
                break
        elif p[i] == '>':    
            if not (int(a[i]) > int(a[i+1])):
                flag = False
                break
    # print('결과는?',flag)        
    if flag:
        temp = ''
        for i in a:
            temp += str(i)
        answer.append(temp)
        
print(answer[-1])
print(answer[0]) 