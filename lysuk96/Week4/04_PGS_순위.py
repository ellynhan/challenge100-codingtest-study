#https://programmers.co.kr/learn/courses/30/lessons/49191
#성공 : but 노드별로 dfs를 하므로 O(N^2)
from collections import defaultdict
visit = []

def solution(n, results):
    win = defaultdict(list)
    lose = defaultdict(list)

    for result in results:
        win[result[0]].append(result[1])
        lose[result[1]].append(result[0])

    def dfs_win(player) :
        visit[player-1] = True
        for node in win[player]:
            if visit[node-1] == False:
                dfs_win(node)

    def dfs_lose(player) :
        visit[player-1] = True
        for node in lose[player]:
            if visit[node-1] == False:
                dfs_lose(node)
    answer = 0
    for i in range(n):
        visit = [False] * n
        dfs_win(i+1)
        dfs_lose(i+1)
        if False not in visit:
            answer+=1
    return answer

#예술풀이 : 승자 - 중간 - 패자 -> 승자와 패자를 엮는 방법을 진행 -> O(N)
# from collections import defaultdict
# def solution(n, results):
#     answer = 0
#     win, lose = defaultdict(set), defaultdict(set)
#     for result in results:
#             lose[result[1]].add(result[0])
#             win[result[0]].add(result[1])

#     for i in range(1, n + 1):
#         for winner in lose[i]: win[winner].update(win[i])
#         for loser in win[i]: lose[loser].update(lose[i])

#     for i in range(1, n+1):
#         if len(win[i]) + len(lose[i]) == n - 1: answer += 1
#     return answer