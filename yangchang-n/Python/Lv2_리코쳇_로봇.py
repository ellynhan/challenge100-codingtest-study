from queue import deque

def solution(board) :
    big_num = 10**8
    count = [[big_num] * len(board[0]) for i in range(len(board))]
    for j in range(len(board)) :
        for k in range(len(board[0])) :
            if board[j][k] == 'R' :
                start = [j, k]
                count[j][k] = 0
            if board[j][k] == 'G' :
                goal = [j, k]
    up, down, left, right = [0, 1], [0, -1], [-1, 0], [1, 0]
    process = deque([[start, up], [start, down], [start, left], [start, right]])
    while process :
        [x, y], [dx, dy] = process.popleft()
        basecount = count[x][y]
        while True :
            if x < 0 or x >= len(board) or y < 0 or y >= len(board[0]) or board[x][y] == 'D' :
                basecount += 1
                if count[x - dx][y - dy] > basecount :
                    count[x - dx][y - dy] = basecount
                    nextstart = [x - dx, y - dy]
                    process.extend([[nextstart, up], [nextstart, down], [nextstart, left], [nextstart, right]])
                break
            x, y = x + dx, y + dy
    print(count)
    if count[goal[0]][goal[1]] == big_num :
        return -1
    return count[goal[0]][goal[1]]
