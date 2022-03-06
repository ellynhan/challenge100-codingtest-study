import sys

N, M = map(int, sys.stdin.readline().split())
N_matrix = []
for i in range(N):
    N_matrix.append(list(map(int, sys.stdin.readline().split())))
#print(N_matrix)

M, K = map(int, sys.stdin.readline().split())
M_matrix = []
for i in range(M):
    M_matrix.append(list(map(int, sys.stdin.readline().split())))
#print(M_matrix)

R_matrix = []

for i in range(N):
    tmp_l = []

    for k in range(K):
        
        res = 0
        for j in range(M):    
            res += N_matrix[i][j] * M_matrix[j][k]  

        tmp_l.append(res)
    
    R_matrix.append(tmp_l)

for l in R_matrix:
    print(*l)
