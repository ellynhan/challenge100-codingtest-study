
equation = input().split('-')

num = []

for i in equation:
    temp = 0
    s = i.split('+')
    for j in s:
        temp += int(j)
        
    num.append(temp)

ans = num[0]*2

for i in num:
    ans -= i

print(ans)