def solution(board, skill):
    answer = 0
    n, m = len(board), len(board[0])

    s = [[0] * (m+1) for _ in range(n+1)]
    for type, r1, c1, r2, c2, degree in skill:
        if type == 1: degree = -degree
        s[r1][c1] += degree
        s[r1][c2+1] -= degree
        s[r2+1][c1] -= degree
        s[r2+1][c2+1] += degree
        
    for i in range(n+1):
        for j in range(1, m+1):
            s[i][j] += s[i][j-1]
    
    for j in range(m+1):
        for i in range(1, n+1):
            s[i][j] += s[i-1][j]
    
    for i in range(n):
        for j in range(m):
            board[i][j] += s[i][j]
            if board[i][j] > 0: answer += 1
    return answer
  
"""
imos 알고리즘 → d차원 배열에서 특정 범위에 val 더할 때, 모든 쿼리를 O(n^d)안에 수행 가능

사각형 구간(r1, c1) ~ (r2, c2)의 꼭지점 활용
- 시작지점 (r1, c1) → val
- 시작지점에서 가로로 끝나는 지점 (r1, c2+1) → -val
- 시작지점에서 세로로 끝나는 지점 (r2+1, c1) → -val
- 사각형이 끝나는 지점 (r2+1, c2+1) → val
"""
