N = int(input())
Field = [[0]*(N+1) for _ in range(N+1)]

apple_num = int(input())
for i in range(apple_num):
  k = list(map(int, input().split()))
  Field[k[0]][k[1]] = 1

direction_count = int(input())
direction_info = []
for i in range(direction_count):
  k = list(input().split())
  direction_info.append([int(k[0]),k[1]])

INF = int(1e9)
second = 1
snake_head_row, snake_head_col = 1,1

d_count = 0
move_direction = 3
move = [(-1,0),(0,-1),(1,0),(0,1)]
snake = [(1,1)]
snake_length = len(snake)

while second: 
  if snake_head_row+move[move_direction][0] < 1 or snake_head_col+move[move_direction][1] < 1 or snake_head_row+move[move_direction][0] > N or snake_head_col+move[move_direction][1] > N:
    break
  else:
    snake_head_row += move[move_direction][0]
    snake_head_col += move[move_direction][1]
    if (snake_head_row,snake_head_col) in snake:
      break
    snake.append((snake_head_row,snake_head_col))
    snake_length = len(snake)

  snake_head = len(snake)-1

  if Field[snake_head_row][snake_head_col] == 1 :
    snake = snake[snake_head-snake_length+1 : ]
    Field[snake_head_row][snake_head_col] = 0
  elif Field[snake_head_row][snake_head_col] == 0 :
    snake_length -= 1
    snake = snake[snake_head-snake_length+1 : ]
  


  if direction_info[d_count][0] == second:
    if direction_info[d_count][1] == 'D':
      move_direction -= 1
      if move_direction < 0:
        move_direction = 3
    else:
      move_direction += 1
      if move_direction>3:
        move_direction = 0
    if d_count < direction_count-1 :
      d_count += 1
  second += 1

print(second)
