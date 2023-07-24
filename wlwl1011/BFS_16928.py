import sys, os, io, atexit
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

#착한 칸이 사다리면, 사다리를 타고 위로 올라간다. ->  원래 있던 칸의 번호보다 크고
# 뱀이 있는 칸에 도착하면, 뱀을 따라서 내려가게 된다. ->  원래 있던 칸의 번호보다 작아진다.

N, M = map(int, input().split())
ladder = [ [0]*2 for _ in range(N) ]
snake = [ [0]*2 for _ in range(M) ]

for i in range(N):
    x, y = map(int, input().split())
    ladder[i] = [x, y]

for i in range(M):
    u, v = map(int, input().split())
    snake[i] = [u, v]    

start = 1
count = 0

ladder.sort(key= lambda x : (x[1],[0])) #최대한 100에 가깝게 정렬한다.
snake.sort(key= lambda x : (x[1], x[0]), reverse=True)

while ladder:
    print(start)
    print(count)
    if 100 - start <= 6 :
        break
    x, y = ladder.pop()
    u, v = snake.pop()
    print(x,y)
    print(u, v)
    flag = True
    #주사위를 걸치고 사다리를 타고 .
    
    if x - start > 6:
        while True:
            if x - start <= 6:
                break
            #여기사이에 꽝이 있는지 확인해야함.
            if start + 6 != u:
                flag = False
                start += 5
                count += 1
        if flag :
            snake.append([u,v]) #안 썼으면 ..
    start = y
    count += 1        

print(count + 1)                

    #사다리를 거치고, 주사위를 몇번 더 돌려서 가는게 빠른지


