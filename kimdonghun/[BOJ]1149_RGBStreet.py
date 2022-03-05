import sys

N = int(sys.stdin.readline())
house = []

for i in range(N):
    house.append(list(map(int, sys.stdin.readline().split())))

d = [[0 for _ in range(3)] for _ in range(len(house))]

for i in range(0, len(house)):
    if i == 0:
        d[i][0] = house[0][0]
        d[i][1] = house[0][1]
        d[i][2] = house[0][2]
    else:
        d[i][0] = min(d[i-1][1], d[i-1][2]) + house[i][0]
        d[i][1] = min(d[i-1][0], d[i-1][2]) + house[i][1]
        d[i][2] = min(d[i-1][0], d[i-1][1]) + house[i][2]

    #print(d)
    
print(min(d[-1]))

#print(house)
#print(d)