import collections


def solution(tickets):
    answer = []

    def dfs(start):
        while graph[start]:
            next_dist = graph[start].pop(0)
            dfs(next_dist)
        answer.append(start)

    graph = collections.defaultdict(list)

    for a, b in sorted(tickets):
        graph[a].append(b)

    dfs("ICN")

    return answer[::-1]