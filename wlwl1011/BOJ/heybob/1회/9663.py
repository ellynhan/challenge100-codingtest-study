import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

global answer
#상하좌우 대각선 체크
def is_valid(r):
    #세로체크
    for i in range(r):
        if row[i]==row[r]:
            return False
        if abs(r-i) == abs(row[r]-row[i]):
            return False
    return True

#r행에 퀸을 놓는다

def put_queen(r):
    global answer
    if r==N:
        answer += 1 
        return  
    for i in range(N):   
        row[r] = i  
        if is_valid(r):
            put_queen(r+1)

answer = 0
N = int(input())
row = [0]*N
put_queen(0)    
print(answer)      