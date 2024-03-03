import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

# 풀이를 제출한 팀의 ID, 문제 번호, 점수

Test = int(input()) #테스트 데이터 개수
for _ in range(Test):
    #팀의 개수 n, 문제의 개수 k, 당신 팀의 ID t, 로그 엔트리의 개수 m
    N, K, T, M = map(int, input().split())
    #점수, 제출 횟수, 마지막 제출 시간
    result = [[ 0 for _ in range(K)] for _ in range(N)]
    time = [0]*N
    count = [0]*N
    #각 풀이에 대한 정보가 제출되는 순서대로
    for t in range(M): 
        #팀 ID i, 문제 번호 j, 획득한 점수 s
        I, J, S = map(int, input().split())

        result[I-1][J-1] = max(result[I-1][J-1],S) #문제 최대값 여기 
        count[I-1] += 1 #제출 횟수
        time[I-1] = t
    new = []
    for idx in range(N):
        new.append([sum(result[idx]),count[idx],time[idx],idx])
    new.sort(key = lambda x : (-x[0],x[1],x[2]))
    for idx in range(N):
        if new[idx][3] == T-1:
            print(idx+1)
            break

