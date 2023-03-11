"""
3x3 선공 o, 후공 x 
가로, 세로, 대각선 중 하나라도 같은 표시이면 승리
실수 : 잘못 표시, 이미 게임 끝남
정답 = 1, 오답 = 0
"""
def solution(board):
    answer = -1
    win = 0
    lose = 0
    count = 0  # 선공 후공 따지기
    
    deL = 0
    deR = 0
    
    # 승부가 이미 났을 경우 따지기
    for i in range(len(board)):

        ga = 0        
        se = 0
        
        #print(board[-(i+1)])
        if board[i][i] == "O":
            deL += 1
        elif board[i][i] == "X":
            deL -= 1
        
        
        if board[i][-(i+1)] == "O":
            deR += 1
        elif board[i][-(i+1)] == "X":
            deR -= 1
        
        for j in range(len(board)):
            
            # 가로
            if board[i][j] == "O":
                ga += 1
                count += 1

            elif board[i][j] == "X":
                ga -= 1
                count -= 1
            
            # 세로
            if board[j][i] == "O":
                se += 1
            elif board[j][i] == "X":
                se -= 1

            if se == 3 or ga == 3:
                win += 1
            elif se == -3 or ga == -3:
                lose += 1

        
        if deL == 3 or deR == 3:
            win += 1
        elif deL == -3 or deR == -3:
            lose += 1
        
    #print(win, count, se, ga)
    
    # 마지막에 2개 빙고 넣을 경우
    if win == 0 and (count == 1 or count == 0) and lose != 1:
        answer = 1
    elif lose == 1 and count == 0 and win == 0:
        answer = 1
    elif win == 1 and count == 1 and lose != 1:
        answer = 1
    elif win == 2 and count == 1 :
        answer = 1

    
    else:
        answer = 0

    
    return answer
