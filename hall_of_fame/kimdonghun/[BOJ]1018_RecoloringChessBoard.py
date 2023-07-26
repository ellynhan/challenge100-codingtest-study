import sys

M, N = map(int, sys.stdin.readline().split())
chess_board = []

for i in range (M):
    chess_board.append(list(sys.stdin.readline()[:-1]))

#print(chess_board)

white_upper_board = [
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
]

black_upper_board = [
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], 
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], 
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
]

block_over = False
min_cnt_change = 3000

for i in range(M):
    for j in range(N):
        
        diff_cnt_white = 0
        diff_cnt_black = 0
        
        block_over = False
        black_flag = False
        white_flag = False

        for k in range(8):
            if(block_over):
                break
            for l in range(8):
                if(i+k >= M or j+l >= N):
                    block_over = True
                    break

                if chess_board[i+k][j+l] != white_upper_board[k][l]:
                    white_flag = True
                    diff_cnt_white += 1
                elif chess_board[i+k][j+l] != black_upper_board[k][l]:
                    black_flag = True
                    diff_cnt_black += 1

        if(block_over):
                break

        #print(diff_cnt_black, diff_cnt_white)

        diff_min_cnt = min(diff_cnt_black, diff_cnt_white)

        if min_cnt_change > diff_min_cnt:
                min_cnt_change = diff_min_cnt
        
print(min_cnt_change)
#print(chess_board)
    