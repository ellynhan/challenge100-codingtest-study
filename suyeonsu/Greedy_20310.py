import sys

s = list(input())
zero, one = s.count('0')//2, s.count('1')//2
i = 0
while one:
    if s[i] == '1':
        s[i] = ''
        one -= 1
    i += 1
i = len(s)-1
while zero:
    if s[i] == '0':
        s[i] = ''
        zero -= 1
    i -= 1
print(''.join(s))
