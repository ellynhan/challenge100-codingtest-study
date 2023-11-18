def combination(number,cnt):
    #print(number,cnt,answer)
    if number > N+1:
        return
    if len(answer) == M:
        print(*answer)
        return
    
    answer.append(number) #넣고
    combination(number+1,cnt+1)
    answer.pop() #안 넣고
    combination(number+1,cnt)

N, M = map(int, input().split())
answer = []
combination(1,0)