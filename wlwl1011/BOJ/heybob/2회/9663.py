import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

global cnt 

def check(node):
    
    #행 체크
    for i in range(node):
        if arr[i] == arr[node]:
            return False
        
        if abs(arr[i] - arr[node]) == abs(i-node):
            return False
        
    #print('check',node)
    return True    
        
    #대각선 체크
       
def nQueen(node):
    global cnt 
    if node == N:
        cnt += 1
        return
    for i in range(N):
        arr[node] = i
        if check(node):
            nQueen(node+1)
       
        

cnt = 0


N = int(input())
arr = [0] * N
nQueen(0)
print(cnt)
