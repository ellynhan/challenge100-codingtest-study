import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

s = input()
N = len(s)
j = N-1
answer = 1
for i in range(N//2):
    if s[i] != s[j]:
        answer = 0
        break
    j -=1
print(answer)    


