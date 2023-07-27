# https://programmers.co.kr/learn/courses/30/lessons/43105
# 정수 삼각형

def solution(triangle):
    for i in range(1, len(triangle)):
        for j in range (i+1):
            if j == 0:
                triangle[i][j] += triangle[i-1][j]
            elif j == i:
                triangle[i][j] += triangle[i-1][j-1]
            else :
                triangle[i][j] = max(triangle[i-1][j]+triangle[i][j],\
                    triangle[i-1][j-1]+ triangle[i][j])

    return max(triangle[-1])

solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]])