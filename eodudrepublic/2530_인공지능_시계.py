import sys

temp = 0
start_hour, start_min, start_sec = map(int,sys.stdin.readline().split())
cooking_time = int(sys.stdin.readline())

cooking_hour = cooking_time // 3600
cooking_time = cooking_time % 3600

cooking_min = cooking_time // 60
cooking_sec = cooking_time % 60

start_sec += cooking_sec
if start_sec >= 60 :
    temp = start_sec // 60
    start_sec = start_sec % 60
else :
    temp = 0

start_min = start_min + cooking_min + temp
if start_min >= 60 :
    temp = start_min // 60
    start_min = start_min % 60
else :
    temp = 0

start_hour = start_hour + cooking_hour + temp
if start_hour >= 24 :
    start_hour = start_hour % 24

print(f"{start_hour} {start_min} {start_sec}")
