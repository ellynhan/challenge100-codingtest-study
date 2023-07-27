# https://www.acmicpc.net/problem/2565
# 1트 실패 : set사용했음, 가장 많이 겹치는 동일한 전깃줄 중 뭘 선택할지에 따라 답이 달라짐
# 2트 : LIS(가장 긴 부분수열) 로 풀어야댐

N = int(input())
lines = [tuple(map(int, input().split(" "))) for _ in range(N)]
lines.sort()
dp = [1] * N

# print(lines)
for i in range(N):
    for j in range(i):
        if lines[j][1]< lines[i][1] and dp[j]+1 > dp[i]:
            dp[i] = dp[j]+1
print(N-max(dp))

# 실패 코드
# from collections import defaultdict
# from itertools import combinations

# def is_intersect(a, b):
#     if (a[0] < b[0] and a[1] < b[1]) \
#         or (a[0] > b[0] and a[1] > b[1]):
#         return False
#     return True

# def get_max_intersect():
#     m = 0
#     now = -1
#     for key in intersect:
#         if m < len(intersect[key]):
#             m = len(intersect[key])
#             now = key
#     return now


# N = int(input())
# ropes = [tuple(map(int, input().split(" "))) for _ in range(N)]
# intersect = defaultdict(set)


# for a, b in combinations(ropes, 2):
#     if is_intersect(a, b):
#         intersect[a] |= {b}
#         intersect[b] |= {a}

# answer = 0
# # print(intersect)
# while True:
#     now = get_max_intersect()
#     if now == -1:
#         break
#     else:
#         answer += 1
#         for tmp in intersect[now]:
#             intersect[tmp] -= {now}
#         intersect[now] = {}

# print(answer)
