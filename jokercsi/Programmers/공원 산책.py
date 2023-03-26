def solution(park, routes):
    answer = []

    for i in range(len(park)):
        for j in range(len(park[0])):
            # 출발점 발견
            if park[i][j] == "S":
                answer.append(i) 
                answer.append(j)
                
                for k in routes:
                    direction = k[0]
                    move = int(k[2])
                    
                    if direction == 'E':
                        #answer[1] += move

                        change=0
                        try:

                            for t in range(1, move+1):
                                check_move = answer[1] + t

                                if park[answer[0]][check_move] == "X":
                                    change = 1
                                    break
                        except:
                            change = 1
                            
                        if change == 0:
                                answer[1] += move
                        
                    elif direction == 'W':
                        change = 0
                        
                        try:
                            if answer[1] - move < 0:
                                change = 1

                            else:                            
                                for t in range(1, move+1):
                                    check_move = answer[1] - t

                                    if park[answer[0]][check_move] == "X":
                                        change = 1
                                        break
                        except:
                            change = 1
                            
                        if change == 0:
                                answer[1] -= move
                        
                    elif direction == 'S':
                        change = 0
                        try:

                            for t in range(1, move+1):
                                check_move = answer[0] + t

                                if park[check_move][answer[1]] == "X":
                                    change = 1
                                    break
                        except:
                            change = 1
                            
                        if change == 0:
                                answer[0] += move
                            
                    elif direction == 'N':
                        change=0
                        try:
                            if answer[0] - move < 0:
                                change = 1

                            else:   
                                                        
                                for t in range(1, move+1):
                                    check_move = answer[0] - t

                                    if park[check_move][answer[1]] == "X":
                                        change = 1
                                        break
                        except:
                            change = 1

                        if change == 0:
                                answer[0] -= move

    
    return answer
