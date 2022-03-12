import sys

num_fruits, snake_len = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

data.sort()

for i in data :
    if i <= snake_len :
        snake_len += 1
    else :
        break

print(snake_len)
