
s = "BAAAB"
k = 2

ans = 0
start = 0

for end in range(len(s)):
    window = s[start: end+1]    ## A
            
    winSize = len(window)       ## 3
    chSet = len(set(window))    ## 3

    print(window, winSize, chSet)

    if k < chSet - 1 or k < winSize - maxf:            
        start += 1
    else:
        if winSize > ans:
            ans = winSize



print(ans)