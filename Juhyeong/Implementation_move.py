n,m = map(int, input().split())
x,y,direction = map(int, input().split())

array = []
for i in range(n):
  array.append(list(map(int, input().split())))

visited_block = [[0]*m for _ in range(n)]
visited_block[x][y] = 1
move_x = [-1,0,1,0]
move_y = [0,1,0,-1]

def turn_left():
  global direction
  direction -= 1
  if(direction == -1):
    direction = 3

count = 1
turn_count = 0

while True:
  turn_left()
  nx = x + move_x[direction] 
  ny = y + move_y[direction]

  if array[nx][ny] == 0 and visited_block[nx][ny] == 0:
    x = nx
    y = ny
    visited_block[x][y] = 1 
    count += 1
    turn_count = 0
    continue

  else:
    turn_count += 1

  if turn_count == 4:
    nx = x - move_x[direction]
    ny = y - move_y[direction]
    if array[nx][ny] != 1:
      x = nx
      y = ny
    else:
      break
    turn_count = 0

print(count)
