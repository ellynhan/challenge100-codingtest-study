import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = []
dictionary = {}

for i in range(N):
    temp = input()
    if temp[0] not in dictionary:
        dictionary[temp[0]] = 1
    else:
        dictionary[temp[0]] += 1

answer = ''
dictionary = dict(sorted(dictionary.items(),key = lambda x: x[0]))
for key, value in dictionary.items():
    if dictionary[key] >= 5:
        answer += str(key)

if not answer:
    print('PREDAJA')
else:
    print(answer)    