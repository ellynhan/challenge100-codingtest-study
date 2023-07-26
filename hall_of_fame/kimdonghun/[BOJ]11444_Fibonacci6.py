import sys

N = int(sys.stdin.readline())
P = 1000000007

def matrix_mul(A, B):
    r_matrix = []

    for i in range(2):
        temp_l = []

        for k in range(2):
            res = 0    
            for j in range(2):
                res += A[i][j] * B[j][k]
                res %= P
            temp_l.append(res)
        
        r_matrix.append(temp_l)

    return r_matrix

def solution(matrix, n):
    if n == 1:
        return matrix
    
    tmp_matrix = solution(matrix, n // 2)

    if n % 2 == 0:
        return matrix_mul(tmp_matrix, tmp_matrix)
    else:
        return matrix_mul(matrix_mul(tmp_matrix, tmp_matrix), matrix)

#matrix_test = [[1,2],[3,4]]
# print(matrix_mul(matrix_test, matrix_test))
#print(solution(matrix_test, 5))

fibonacci_matrix = [[1,1],[1,0]]
print(solution(fibonacci_matrix, N)[0][1])
