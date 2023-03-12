from collections import deque

compare = {1:[(1, 2), (2, 3), (3, 4)], 2:[(2, 1), (2, 3), (3, 4)], 3:[(3, 2), (3, 4), (2, 1)], 4:[(4, 3), (3, 2), (2, 1)]}
wheel = [deque(list(map(int, list(input())))) for _ in range(4)]
k = int(input())
direction = [0] * 4

def getDirection(srt):
    for a, b in compare[srt]:
        ai, bi = (2, 6) if a < b else (6, 2)
        if direction[a-1] != 0 and wheel[a-1][ai] != wheel[b-1][bi]:
            direction[b-1] = -1 if direction[a-1] == 1 else 1
        else:
            direction[b-1] = 0

for _ in range(k):
    i, d = map(int, input().split())
    direction[i-1] = d
    getDirection(i)
    for num, dir in enumerate(direction):
        wheel[num].rotate(dir)

answer = 0
for i, s in zip(range(4), [1, 2, 4, 8]):
    answer += s if wheel[i][0] == 1 else 0
print(answer)
