def solution(board, moves):
    basket = []
    removed = 0 

    n = len(board)

    for move in moves:
        col = move - 1

        for row in range(n):
            if board[row][col] != 0:
                doll = board[row][col]
                board[row][col] = 0

                if basket and basket[-1] == doll:
                    basket.pop()
                    removed += 2
                else:
                    basket.append(doll)

                break

    return removed
