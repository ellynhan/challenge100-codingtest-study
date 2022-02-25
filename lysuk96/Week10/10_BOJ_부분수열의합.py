# https://www.acmicpc.net/problem/1182
# 백트래킹 : python3로 하면 시간초과, pypy3로 하면 통과..?

def tracking(idx, depth):
    global answer
    if depth == d and sum(l)==S:
        # print(l)
        answer+=1
        return
    for i in range(idx, N):
        l.append(num[i])
        tracking(i+1,depth+1)
        l.pop(-1)


N, S = map(int, input().split(" "))
num = list(map(int, input().split(" ")))
d= 0
l = []

global answer
answer=0

for i in range(1, N+1):
    l=[]
    d=i
    tracking(0,0)
    
print(answer)

# combinations 쓰니 간단히 해결
# from itertools import combinations

# N, S = map(int, input().split(" "))
# num = list(map(int, input().split(" ")))

# answer = 0
# for i in range(1, N+1):
#     for comb in combinations(num, i):
#         if sum(comb) == S:
#             answer+=1
# print(answer)