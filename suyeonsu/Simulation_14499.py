def move(d, x, y):
    if d == 1: 
        dice['u'], dice['r'], dice['d'], dice['l'] = dice['l'], dice['u'], dice['r'], dice['d']
    elif d == 2:
        dice['u'], dice['r'], dice['d'], dice['l'] = dice['r'], dice['d'], dice['l'], dice['u']
    elif d == 3:
        dice['u'], dice['b'], dice['d'], dice['f'] = dice['f'], dice['u'], dice['b'], dice['d']
    else:
        dice['u'], dice['b'], dice['d'], dice['f'] = dice['b'], dice['d'], dice['f'], dice['u']

    if board[x][y] == 0:
        board[x][y] = dice['d']
    else:
        dice['d'] = board[x][y]
        board[x][y] = 0

n, m, x, y, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dice = {'u':0, 'd':0, 'l':0, 'r':0, 'f':0, 'b':0}
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

for q in list(map(int, input().split())):
    nx, ny = x + dx[q], y + dy[q]
    if 0 <= nx < n and 0 <= ny < m:
        x, y = nx, ny
        move(q, x, y)
        print(dice['u'])
        
"""
시뮬레이션 문제의 경우 (인덱스 활용 등) 패턴이 있는 경우가 있음
손으로 그려볼 수 있다면 그려서 알아내자
"""
