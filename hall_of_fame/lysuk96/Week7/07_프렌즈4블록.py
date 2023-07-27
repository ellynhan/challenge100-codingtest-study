#https://programmers.co.kr/learn/courses/30/lessons/17679

# 예술풀이 (행렬 -> 열행으로 바꾸고 zfill,rjust 사용 (떨어뜨리기))
def rectangle(x, y, arr):
    same = arr[x][y] == arr[x+1][y+1] \
        == arr[x][y+1] == arr[x+1][y]
    if same:
        return True
    return False
    
def solution(m, n, board):
    string = ''.join(board)
    arr = []
    answer = 0
    
    #initialize
    # 행열 -> 열행 transpose
    for i in range(n):
        tmp = []
        for j in range(m):
            tmp.append(string[j*n + i])
        arr.append(tmp)
    
    while True:
        # 사각형 찾기
        eli = set()
        stop = True
        
        for i in range(n-1):
            for j in range(m-1):
                if arr[i][j] != '0' and rectangle(i, j, arr):
                    eli |= {(i, j), (i+1, j), (i, j+1), (i+1, j+1)}
                    stop = False
        print(eli)
        if stop:
            break
            
        # 사각형 삭제하기
        answer += len(eli)
        for i, j in eli:
            arr[i][j] = '0'

        # 떨어뜨리기
        for j in range(n):
            arr[j] = list(''.join(arr[j]).replace("0","").zfill(m))
    
        
    return answer

print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))

# 3중포문 사용 비효율적 풀이 (떨어뜨리기)

# def solution(m, n, board):
#     board = [list(x) for x in board]
#     def rectangle(x,y):
#         move = [(0,1), (1,0), (1,1)]
#         for dy, dx in move:
#             if board[y][x] != board[y+dy][x+dx]:
#                 return False

#         return True

#     answer = 0

#     while True:
#         eli = set()
#         flag = True
#         for y in range(m-1):
#             for x in range(n-1):
#                 if board[y][x] != ' ' and rectangle(x, y):
#                     eli |= {(x,y), (x,y+1), (x+1, y), (x+1, y+1)}
#                     flag = False
#         if flag:
#             break
#         answer+=len(eli)
#         # eli = (sorted(eli, key = lambda x: x[0]))
#         # eli = (sorted(eli, key = lambda x: x[1]))

#         # print(eli)
#         # eliminate
#         for x,y in eli:
#             board[y][x] = ' '
#         # break

#         for _ in range(m):
#             for y in range(m-1):
#                 for x in range(n):
#                     if board[y+1][x] == ' ':
#                         board[y+1][x], board[y][x] = board[y][x], board[y+1][x]
#         # print(board)



#     return answer