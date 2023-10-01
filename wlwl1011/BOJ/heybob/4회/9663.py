import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

global answer

def check(n):
    
    for i in range(n):
        if chess[i] == chess[n]: #같은 행
            return False
        if abs(chess[i]-chess[n]) == abs(i-n): #대각선
            return False
    return True    

def nQueen(n):
    
    global answer
    if n == N:
        answer += 1
        return

    for i in range(N):
        chess[n] = i
        if check(n):
            nQueen(n+1)
          


N = int(input())
chess = [0] * N
answer = 0
nQueen(0)
print(answer)



    

