import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

global answer_white
global answer_blue

def check(x,y,n):
    color = arr[x][y]
    for i in range(x,x+n):
        for j in range(y,y+n):
            if color != arr[i][j]:
                return -1
    return color       

def splitPaper(x,y,n):
    temp = check(x,y,n) 
    if temp != -1:
        global answer_white
        global answer_blue

        if temp == 0:
            answer_white += 1
        else:
            answer_blue += 1    
        
        return
    else:
        splitPaper(x,y,n//2)
        splitPaper(x+n//2,y,n//2)
        splitPaper(x,y+n//2,n//2)
        splitPaper(x+n//2,y+n//2,n//2)

    

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

answer_white = 0
answer_blue = 0
splitPaper(0,0,N)
print(answer_white)
print(answer_blue)