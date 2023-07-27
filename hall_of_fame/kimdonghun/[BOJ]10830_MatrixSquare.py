import sys

N, B = map(int, sys.stdin.readline().split())
P = 1000

N_matrix = []
for i in range(N):
    N_matrix.append(list(map(int, sys.stdin.readline().split())))
#print(N_matrix)

def solution(matrix, B):
    if B == 1:
        return matrix_mod(matrix)

    tmp_matrix = solution(matrix, B // 2)

    if B % 2 == 0:
        return matrix_mul(tmp_matrix, tmp_matrix)
    else:
        return matrix_mul(matrix_mul(tmp_matrix, tmp_matrix), matrix)

def matrix_mul(A,B):
    sol_matrix = []
    for i in range(N):
        tmp_l = []

        for k in range(N):
            
            res = 0

            for j in range(N):    
                res += (A[i][j] % P * B[j][k] % P) % P
                res %= P
            
            tmp_l.append(res)
        
        sol_matrix.append(tmp_l)

    return sol_matrix

def matrix_mod(A):
    for i in range(N):
        for j in range(N):
            A[i][j] %= P

    return A

ans_matrix = solution(N_matrix, B)
for l in ans_matrix:
    print(*l)
