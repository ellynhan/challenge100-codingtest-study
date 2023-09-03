import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = input()

# 가능한 문자열 중 사전순으로 가장 빠른 것을 출력한다.
# 길이는 2이상 5 이하
#짝수개의 0과 짝수개의 1로 이루어져 있다.

#s의 길이는 4의 배수이다.
#s의 홀수번째 문자는 1, 짝수번째 문자는 0 이다.
count_one = 0
count_zero = 0

for i in S:
    if i == '1':
        count_one += 1
    else:
        count_zero += 1
#print(count_one, count_zero)
for i in range(count_one//2):
    S = S.replace('1','',1)
#print(S)    
new_S = []
check = 0

for i in range(len(S)-1,-1,-1):

    if S[i] == '0':
        check += 1
    if S[i] == '0' and check > (count_zero//2):
       # print('?')
        new_S.append(S[i])
    elif S[i] == '1':
        new_S.append(S[i])  
    #print(S[i], new_S, check)    


    

new_S.reverse()
S = ''
for i in range(len(new_S)):
    S += str(new_S[i])
print(S)

