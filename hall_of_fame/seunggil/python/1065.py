n = int(input())

ans = 0
for i in range(1,n+1):
    if i < 100:
        ans +=1
    else:
        s = str(i)
        diff = ord(s[0]) - ord(s[1])
        for i in range(1,len(s)-1):
            if ord(s[i]) - ord(s[i+1]) != diff:
                break
            if i == len(s) - 2:
                ans += 1
print(ans)