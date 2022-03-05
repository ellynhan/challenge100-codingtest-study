#
#   2675
#   string
# #
# 

t = int(input())
for i in range(t):
    r,s = map(str, input().split())
    for j in range(len(s)):
        for k in range(int(r)):
            print(s[j], end='')
    print()
