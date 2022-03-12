import sys

bowls = list(sys.stdin.readline().strip())
ex_b = "N"
total_height = 0
for b in bowls :
    if b == ex_b :
        total_height += 5
    else :
        ex_b = b
        total_height += 10
# print(bowls)
print(total_height)
