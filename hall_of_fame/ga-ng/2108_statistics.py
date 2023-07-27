import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())

numl = []

sumAll = 0
for i in range(n):
    temp = int(input())
    numl.append(temp)
    sumAll += temp

numl.sort()
    

print(round(sumAll/n))
print(numl[n//2])


cnt = Counter(numl).most_common()

if len(cnt) > 1 and cnt[0][1] == cnt[1][1]:
    print(cnt[1][0])
else:
    print(cnt[0][0])


print(numl[-1] - numl[0])