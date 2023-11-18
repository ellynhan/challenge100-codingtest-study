import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
dictionary = dict()
for _ in range(N):
    name, day, month, year = input().split()
    dictionary[name] = [int(year), int(month), int(day)]

dictionary = dict(sorted(dictionary.items(), key = lambda x :(x[1][0],x[1][1],x[1][2]),reverse=True))

first = 1
last = N
cnt = 0
for key, value in dictionary.items():
    
    cnt += 1
    if cnt == first:
        print(key)
    if cnt == last:
        print(key)    


