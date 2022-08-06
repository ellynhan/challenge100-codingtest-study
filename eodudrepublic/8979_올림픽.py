import sys

N, K = map(int, sys.stdin.readline().split())

target_score = -1
total_result = []
tt = 10000
for i in range(N) :
    name, g, s, b = map(int, sys.stdin.readline().split())
    score = (tt**2)*g + tt*s + b
    if target_score == -1 :
        if name == K :
            target_score = score
    else :
        if score <= target_score :
            continue
    total_result.append(score)

total_result.sort(reverse=True)
rank = total_result.index(target_score) + 1
# print(total_result)
print(rank)
