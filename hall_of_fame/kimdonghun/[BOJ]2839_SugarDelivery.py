import sys

N = int(sys.stdin.readline())

cur_sugar = 0
min_sugar = 5001

for i in range(N // 5 + 1) :
    for j in range(N // 3 + 1) :
        cur_sugar = (i * 5) + (j * 3)

        if(cur_sugar == N) :
            if(min_sugar > i + j) :
                min_sugar = i + j

if(min_sugar == 5001) :
    print(-1)
else:
    print(min_sugar)