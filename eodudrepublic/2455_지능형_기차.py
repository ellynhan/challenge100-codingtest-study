import sys

num_people = 0
max_people = 0
for i in range(4) :
    num_out, num_in = map(int, input().split())
    num_people = num_people + num_in - num_out
    if num_people > max_people :
        max_people = num_people
print(max_people)
