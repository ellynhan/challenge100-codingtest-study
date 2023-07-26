import sys

N = int(sys.stdin.readline())
S = 1

for i in range(N) :
    S += i * 6

    if S >= N :
        min_room = i
        break
        
print(min_room + 1)
