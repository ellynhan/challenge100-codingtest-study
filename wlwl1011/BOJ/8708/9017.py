import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

T = int(input())
for i in range(T):
    N = int(input())
    
    #팀 번호를 나타내는 N 개의 정수
    arr = list(map(int, input().split()))
    team_num = max(arr)
    check = [0]*(team_num+1)
    for index in arr:
        check[index] += 1
    #print(check)    
    score = [[] for _ in range(team_num+1)]    
    rank = 1
    for index in arr:
        if check[index] >= 6:
            score[index].append(rank)
            rank += 1
    #print(score)
    sum_score = [0]*(team_num+1)        
    for index in range(1, team_num+1):    
        if check[index] >= 6:
            sum_score[index] = sum(score[index][:4]) 
    #print(sum_score)         
    score_min = int(1e9) 
    answer = 0        
    for index in range(1, team_num+1):
        if check[index] >= 6:
            if sum_score[index] < score_min:
                answer = index
                score_min = sum_score[index]
            elif sum_score[index] == score_min:
               
                if score[index][4] < score[answer][4]:
                    answer = index    
    
    print(answer)