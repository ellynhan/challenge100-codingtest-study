from itertools import permutations

n = int(input())
inning = [list(map(int, input().split())) for _ in range(n)]
answer = 0
for order in list(map(list, permutations(range(1, 9), 8))):
    order = order[:3] + [0] + order[3:]
    score = 0
    i = 0
    for k in range(n):
        out = 0
        base1, base2, base3 = 0, 0, 0
        while out < 3:
            res = inning[k][order[i]]
            if res == 0:
                out += 1
            elif res == 1:
                score += base3
                base1, base2, base3 = 1, base1, base2
            elif res == 2:
                score += base2 + base3
                base1, base2, base3 = 0, 1, base1
            elif res == 3:
                score += base1 + base2 + base3
                base1, base2, base3 = 0, 0, 1
            else:
                score += base1 + base2 + base3 + 1
                base1, base2, base3 = 0, 0, 0
            i += 1
            if i == 9:
                i = 0
    answer = max(answer, score)
print(answer)
