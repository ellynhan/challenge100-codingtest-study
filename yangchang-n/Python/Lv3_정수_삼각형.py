def solution(triangle) :
    for i in range(len(triangle) - 1) :
        for j in range(len(triangle[-i]) - 1) :
            triangle[-i - 1][j] += max(triangle[-i][j], triangle[-i][j + 1])
    answer = triangle[0][0] + max(triangle[1][0], triangle[1][1])
    return answer
