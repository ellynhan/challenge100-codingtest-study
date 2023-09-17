import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))


#처음 입장한 플레이어의 레벨을 기준으로 -10부터 +10까지 입장 가능

#입장 가능한 방이 있다면 입장시킨 후 방의 정원이 모두 찰 때까지 대기
# 입장이 가능한 방이 여러 개라면 먼저 생성된 방에 입장

#플레이어수, 방의 정원
P, M = map(int, input().split())
game = [[]]

level, name = input().split()
game[0].append([level, name])

for _ in range(P-1):
    level, name = input().split()
    flag = False    
    for i in range(len(game)):
        #print(game[i])
        if int(game[i][0][0]) - 10 <= int(level) <= int(game[i][0][0]) + 10 and len(game[i]) < M:
            game[i].append([level,name])
            flag = True
            break
            
    if flag == False:
        game.append([[level,name]])  




for i in range(len(game)):
    if len(game[i]) == M:
        print('Started!')
    else:
        print('Waiting!')        
    game[i].sort(key = lambda x: (x[1]))
    for j in range(len(game[i])):
        print(game[i][j][0], game[i][j][1])         
