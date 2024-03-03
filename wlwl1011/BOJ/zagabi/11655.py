import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = list(input())
N = len(s)
new_s = [0 for _ in range(N)]
check = []

for i in 'abcdefghijklmnopqrstuvwxyz':
    check.append(i)

for i in range(N):
    if s[i].isdigit():
        new_s[i] = s[i] 
    elif s[i] == ' ':
        new_s[i] = s[i]     
    elif s[i].isupper():    
        new_s[i] = check[(check.index(s[i].lower()) + 13) % len(check)].upper()
    else:
         new_s[i] = check[(check.index(s[i]) + 13) % len(check)]   

for i in new_s:
    print(i,end='')