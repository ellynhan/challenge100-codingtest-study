#백준 1016번 제곱ㄴㄴ수
#골드 1
from math import sqrt

mi, ma = map(int, input().split())
cnt = 0
end_sqrt = int(sqrt(ma))
rs = []
d = {x:0 for x in range(mi, ma+1)}
for i in range(end_sqrt+1):
    if i==0 or i==1:
        continue
    sq = i**2
    for j in range(mi//sq, (ma//sq)+1):
        num = j*sq
        if mi<=num<=ma:
            d[num] +=1
print(len([v for v in d.values() if v==0]))
