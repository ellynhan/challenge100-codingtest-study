# tic tac toe
grid = [['-' for i in range(3)] for j in range(3)]
dr = draw(grid)
round = 0
status = 'playing'
while status == 'playing':
    if round % 2 == 0:
        player = 'X'
    else:
        player = 'O'
    print(f"{player}의 턴입니다.")
    row = int(input("행 번호를 선택하세요 (1-3): "))
    col = int(input("열 번호를 선택하세요 (1-3): "))
    print("\n====================================\n")
    grid[row-1][col-1] = player
    draw(grid)
    round += 1
    for i in range(3):
        if grid[i][:] == [player,player,player] or grid[:][i] == [player,player,player]:
            print(f"{player}가 이겼습니다!")
            status = 'end'
            break
        elif grid[0][0] == grid[1][1] == grid[2][2] == player or grid[0][2] == grid[1][1] == grid[2][0] == player:
            print(f"{player}가 이겼습니다!")
            status = 'end'
            break
        else:
            continue
