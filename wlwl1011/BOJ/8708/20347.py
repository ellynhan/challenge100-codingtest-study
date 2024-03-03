import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))
from collections import defaultdict

T = int(input())


# 가장 길던, 가장 짧던, 문자열의 끝에는 같은 문자가 반복이된다.

for _ in range(T):
    W = input() #문자열
    K = int(input())
    #문자가 K개 이상 존재하는 경우, dict에 저장한다.
    alpa = defaultdict(list)
    for i in range(len(W)):
        if W.count(W[i]) >= K:
            alpa[W[i]].append(i)
    if not alpa:
        print(-1)
    else:    
        min_val, max_val = int(1e9), 0
        #print(alpa)
        for i in alpa:
            #print(i)
            for j in range(len(alpa[i])- K + 1):
                #어떤 문자 K개를 포함하는 문자열의 길이를 구함.
                #print(alpa[i][j+K-1],alpa[i][j] )
                length = alpa[i][j+K-1] - alpa[i][j] + 1
                min_val = min(min_val, length)
                max_val = max(max_val, length)
        print(min_val,max_val)    
      