def dfs(i, computers, visit):
    if visit[i]:
        return

    visit[i] = True

    for index, connected in enumerate(computers[i]):
        if connected:
            dfs(index, computers, visit)


def solution(n, computers):
    answer = 0
    visit = [0 for _ in range(len(computers))]

    for i in range(len(computers)):
        if not visit[i]:
            dfs(i, computers, visit)
            answer += 1
    return answer