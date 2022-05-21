n = int(input())
di = dict()

for i in range(n):
    word = input().split(".")
    if word[1] not in di:
        di[word[1]] = 1
    else:
        di[word[1]] += 1

di2 = sorted(di.items())

for k,v in di2:
    print(k.rstrip(), v)
