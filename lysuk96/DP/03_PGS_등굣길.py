# 등굣길
# 1트 : 행렬 반대로 해서 틀림 (특히 puddles)

def solution(m, n, puddles):
    path = [[0]*m for _ in range(n)]
    
    #initialize
    for puddle in puddles :
        path[puddle[1]-1][puddle[0]-1] = -1
    for i in range(m):
        if path[0][i] == -1:
            break
        path[0][i] = 1
    for i in range(n):
        if path[i][0] == -1:
            break
        path[i][0] = 1
    
    for i in range(1, n):
        for j in range(1, m):
            if path[i][j] == -1 or (path[i-1][j] == -1 and path[i][j-1] == -1): # 더 나은 풀이 : path[i][j] == -1 -> path[i][j] = 0
                continue
            if path[i-1][j] == -1 :
                path[i][j] = path[i][j-1]
            elif path[i][j-1] == -1 :
                path[i][j] = path[i-1][j]
            else:
                path[i][j] = path[i-1][j] + path[i][j-1]
    
    answer = path[n-1][m-1]
    return answer % 1000000007

print(solution(4,3,[[2, 2]]))