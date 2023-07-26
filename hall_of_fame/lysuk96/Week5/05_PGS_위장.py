#https://programmers.co.kr/learn/courses/30/lessons/42578
# 1트 실패 : 1번 시간초과 (옷 30, 종류 30일 때)
# 효율적 풀이 : 안입었을 때를 생각하기

from collections import defaultdict

def solution(clothes):
    dressroom = defaultdict(int)
    for cloth in clothes:
        dressroom[cloth[1]] += 1
    
    dress_num = []
    for dress in dressroom:
        dress_num.append(dressroom[dress]+1)
    
    answer = 1
    for i in range(len(dress_num)):
        answer*=dress_num[i]
    return answer-1

# 비효율적 풀이 : combination 구해서 직접 더하기
# from collections import defaultdict
# from itertools import combinations

# def solution(clothes):
#     dressroom = defaultdict(int)
#     for cloth in clothes:
#         dressroom[cloth[1]] += 1
    
    
#     dress_num = []
#     for dress in dressroom:
#         dress_num.append(dressroom[dress]+1)
    
#     if(len(dress_num)) == 30 :
#         return 2**30 -1
    
#     answer = 0
#     for i in range(1, len(dress_num)+1):
#         combi = list(combinations(dress_num, i))
#         for num in combi:
#             tmp = 1
#             for j in range(i):
#                 tmp *= num[j]
#             answer+=tmp
#     return answer

